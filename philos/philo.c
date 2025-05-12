/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:47:23 by jemorais          #+#    #+#             */
/*   Updated: 2025/05/12 15:20:28 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// philo.c

#include "philo.h"

bool	start_threads(t_philo *philos, t_table *table)
{
	int	i;

	i = 0;
	while (i < table->number_philos)
	{
		if (pthread_create(&philos[i].thread_id, NULL, philo_routine, &philos[i]) != 0)
		{
			printf("Philo %d error\n", philos[i].id);
			return (false);
		}
		i++;
	}
	return (true);
}
