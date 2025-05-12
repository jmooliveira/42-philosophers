/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:26:00 by jemorais          #+#    #+#             */
/*   Updated: 2025/05/12 15:38:43 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// routine.c

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

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_action(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	print_action(philo, "has taken a fork");
	print_action(philo, "is eating");
	philo->last_meal = get_time_ms();
	usleep(philo->table->time_to_eat * 1000);
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep (1000);
	while (42)
	{
		eat(philo);
		print_action(philo, "is sleeping");
		usleep(philo->table->time_to_sleep * 1000);
		print_action(philo, "is thinking");
	}
	return (NULL);
}
