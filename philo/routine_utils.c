/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:29:36 by jemorais          #+#    #+#             */
/*   Updated: 2025/06/11 16:47:30 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// routine_utils.c

#include "philo.h"

void	philo_loop(t_philo *philo)
{
	while (!check_stop_condition(philo))
	{
		if (take_forks(philo))
		{
			if (check_stop_condition(philo))
			{
				drop_forks(philo);
				break ;
			}
			eat(philo);
			drop_forks(philo);
			if (check_stop_condition(philo))
				break ;
			sleep_think(philo);
		}
	}
}

bool	take_fork_even(t_philo *philo)
{
	if (check_stop_condition(philo))
		return (false);
	if (pthread_mutex_lock(philo->left_fork) != 0)
		return (false);
	print_action(philo, "has taken a fork");
	if (check_stop_condition(philo)
		|| pthread_mutex_lock(philo->right_fork) != 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		return (false);
	}
	print_action(philo, "has taken a fork");
	return (true);
}

bool	take_fork_odd(t_philo *philo)
{
	if (check_stop_condition(philo)
		|| pthread_mutex_lock(philo->right_fork) != 0)
		return (false);
	print_action(philo, "has taken a fork");
	if (check_stop_condition(philo)
		|| pthread_mutex_lock(philo->left_fork) != 0)
	{
		pthread_mutex_unlock(philo->right_fork);
		return (false);
	}
	print_action(philo, "has taken a fork");
	return (true);
}
