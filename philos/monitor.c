/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:11:18 by jemorais          #+#    #+#             */
/*   Updated: 2025/05/14 17:34:04 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// monitor.c

#include "philo.h"

long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	print_action(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->table->print_lock);
	printf("%ld %d %s\n", get_time_ms() - philo->table->start_time,
		philo->id, msg);
	pthread_mutex_unlock(&philo->table->print_lock);
}

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
	int		i;
	long	time_now;

	philos = (t_philo *)arg;
	table = philos[0].table;
	while (42)
	{
		i = 0;
		while (i < table->number_philos)
		{
			time_now = get_time_ms();
			if ((time_now - philos[i].last_meal > table->time_to_die))
			{
				died(table, philos, time_now, i);
				return (NULL);
			}
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}
