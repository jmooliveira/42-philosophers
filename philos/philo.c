/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:47:23 by jemorais          #+#    #+#             */
/*   Updated: 2025/05/09 17:40:05 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// philo.c

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo = NULL;

	(t_philo *)arg;
	printf("Philo %d start routine\n", philo->id);
	return (NULL);
}

bool	start_simulation(t_philo *philos, t_table *table)
{
	int	i;

	i = 0;
	while (i < table->number_philos)
	{
		printf("%d\n", i);
		if (pthread_create(&philos[i].thread_id, NULL,
				philo_routine, &philos[i]) != 0)
		{
			printf("Philo %d error\n", philos[i].id);
			return (false);
		}
		i++;
	}
	return (true);
}
