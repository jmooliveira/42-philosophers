/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:26:00 by jemorais          #+#    #+#             */
/*   Updated: 2025/05/14 17:48:30 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// routine.c

#include "philo.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_action(philo, "has taken left fork");
	pthread_mutex_lock(philo->right_fork);
	print_action(philo, "has taken right fork");
}

void	eat(t_philo *philo)
{
	print_action(philo, "is eating");
	philo->last_meal = get_time_ms();
	usleep(philo->table->time_to_eat * 1000);
	philo->meals_eaten++;
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	sleep_think(t_philo *philo)
{
	print_action(philo, "is sleeping");
	usleep(philo->table->time_to_sleep * 1000);
	print_action(philo, "is thinking");
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep (1000);
	while (!check_stop_condition(philo))
	{
		take_forks(philo);
		eat(philo);
		drop_forks(philo);
		sleep_think(philo);
	}
	return (NULL);
}
