/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:45:41 by jemorais          #+#    #+#             */
/*   Updated: 2025/05/07 17:12:03 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// free.c

#include "philo.h"

void	free_and_close(t_table *table, t_philo *philos)
{
	if (table->forks)
		free(table->forks);
	if (philos)
		free(philos);
	free(table);
	exit(0);
}
