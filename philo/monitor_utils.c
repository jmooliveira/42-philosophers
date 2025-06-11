/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:34:41 by jemorais          #+#    #+#             */
/*   Updated: 2025/06/11 15:45:20 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// monitor_utils.c

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
	if (check_stop_condition(philo))
	{
		pthread_mutex_unlock(&philo->table->print_lock);
		return ;
	}
	printf("%ld %d %s\n", get_time_ms() - philo->table->start_time,
		philo->id, msg);
	pthread_mutex_unlock(&philo->table->print_lock);
}

bool	check_philo_death(t_philo *philo, t_table *table,
			long time_now, int index)
{
	pthread_mutex_lock(&philo->meal_mutex);
	if (time_now - philo->last_meal > table->time_to_die)
	{
		pthread_mutex_unlock(&philo->meal_mutex);
		died(table, philo, time_now, index);
		return (true);
	}
	pthread_mutex_unlock(&philo->meal_mutex);
	return (false);
}

bool	all_philos_ate(t_table *table, t_philo *philos)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < table->number_philos)
	{
		pthread_mutex_lock(&philos[i].meal_mutex);
		if (philos[i].meals_eaten >= table->number_meals)
			count++;
		pthread_mutex_unlock(&philos[i].meal_mutex);
		i++;
	}
	return (count == table->number_philos);
}
