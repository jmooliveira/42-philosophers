/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:45:41 by jemorais          #+#    #+#             */
/*   Updated: 2025/05/26 17:00:48 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// free.c

#include "philo.h"

void	free_and_close(t_table *table, t_philo *philos)
{
	int	i;

	if (table)
	{
		if (table->forks)
		{
			i = 0;
			while (i < table->number_philos)
			{
				pthread_mutex_destroy(&table->forks[i]);
				i++;
			}
			free(table->forks);
		}
		pthread_mutex_destroy(&table->print_lock);
		pthread_mutex_destroy(&table->stop_mutex);
		free(table);
	}
	if (philos)
		free(philos);
}

void	ft_free(t_table **table)
{
	free(*table);
	exit(EXIT_ERROR);
}
