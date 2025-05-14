/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:11:18 by jemorais          #+#    #+#             */
/*   Updated: 2025/05/14 15:56:38 by jemorais         ###   ########.fr       */
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

void	*monitor(void *arg)
{

}

void	take_forks()
{

}

void	drop_forks()
{

}

void	sleep_think()
{

}
