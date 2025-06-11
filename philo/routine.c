/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:26:00 by jemorais          #+#    #+#             */
/*   Updated: 2025/06/11 14:58:11 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// routine.c

#include "philo.h"

bool	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
		return (take_fork_even(philo));
	else
		return (take_fork_odd(philo));
}

void	eat(t_philo *philo)
{
	long	start_time;

	if (check_stop_condition(philo))
		return ;
	print_action(philo, "is eating");
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = get_time_ms();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_mutex);
	start_time = get_time_ms();
	while (!check_stop_condition(philo) && get_time_ms()
		- start_time < philo->table->time_to_eat)
		usleep(200);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	print_action(philo, "has dropped forks");
}

void	sleep_think(t_philo *philo)
{
	long	start_time;

	if (check_stop_condition(philo))
		return ;
	print_action(philo, "is sleeping");
	start_time = get_time_ms();
	while (!check_stop_condition(philo) && get_time_ms()
		- start_time < philo->table->time_to_sleep)
		usleep(200);
	if (check_stop_condition(philo))
		return ;
	print_action(philo, "is thinking");
	start_time = get_time_ms();
	while (!check_stop_condition(philo) && get_time_ms()
		- start_time < philo->table->time_to_think)
		usleep(200);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->table->number_philos == 1)
	{
		print_action(philo, "has taken a fork");
		usleep(philo->table->time_to_die * 1000);
		print_action(philo, "died");
		return (NULL);
	}
	philo_loop(philo);
	return (NULL);
}
