/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:39:04 by jemorais          #+#    #+#             */
/*   Updated: 2025/05/12 15:22:02 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.c

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;
	t_philo	*philos;

	table = ft_calloc(1, sizeof(t_table));
	if (!validate_and_init_args(argc, argv))
		exit (EXIT_ERROR);
	philos = NULL;
	init_table(table, argv);
	if (/*!init_table(table, argv) || */!init_forks(table) || !init_philo(&philos, table))
	{
		printf("Init Error");
		free_and_close(table, philos);
		exit (INIT_ERROR);
	}
	if (!start_threads(philos, table))
	{
		free_and_close(table, philos);
		exit (INIT_ERROR);
	}
	while (1)
		usleep(1000);
	free_and_close(table, philos);
}
