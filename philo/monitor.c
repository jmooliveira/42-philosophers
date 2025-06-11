/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:11:18 by jemorais          #+#    #+#             */
/*   Updated: 2025/06/11 15:36:49 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// monitor.c

#include "philo.h"

bool	check_stop_condition(t_philo *philo)
{
	bool	stop;

	pthread_mutex_lock(&philo->table->stop_mutex);
	stop = philo->table->stop;
	pthread_mutex_unlock(&philo->table->stop_mutex);
	return (stop);
}

void	died(t_table *table, t_philo *philos, long time_now, int i)
{
	pthread_mutex_lock(&table->print_lock);
	printf("%ld %d died\n", time_now - table->start_time, philos[i].id);
	pthread_mutex_unlock(&table->print_lock);
	pthread_mutex_lock(&table->stop_mutex);
	table->stop = true;
	pthread_mutex_unlock(&table->stop_mutex);
}

void	*monitor(void *arg)
{
	t_philo	*philos;
	t_table	*table;

	philos = (t_philo *)arg;
	table = philos[0].table;
	while (true)
	{
		if (monitor_philos(table, philos))
			return (NULL);
		usleep(200);
	}
	return (NULL);
}

bool	monitor_philos(t_table *table, t_philo *philos)
{
	int		i;
	long	time_now;

	i = 0;
	while (i < table->number_philos)
	{
		time_now = get_time_ms();
		if (check_philo_death(&philos[i], table, time_now, i))
			return (true);
		i++;
	}
	if (table->number_meals > 0 && all_philos_ate(table, philos))
	{
		pthread_mutex_lock(&table->stop_mutex);
		table->stop = true;
		pthread_mutex_unlock(&table->stop_mutex);
		return (true);
	}
	return (false);
}
