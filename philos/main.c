/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:39:04 by jemorais          #+#    #+#             */
/*   Updated: 2025/05/09 16:58:31 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.c

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;
	t_philo	*philos;
	int		i;

	table = ft_calloc(1, sizeof(t_table));
	if (!validate_and_init_args(argc, argv))
		exit (EXIT_ERROR);
	philos = NULL;
	init_table(table, argv);
	if (!init_forks(table) || !init_philo(&philos, table))
	{
		printf("Init Error");
		exit (INIT_ERROR);
	}
	if (!start_simulation(philos, table))
	{
		printf("Init Simulation Error\n");
		exit (INIT_ERROR);
	}
	i = 0;
	while (i < table->number_philos)
	{
		pthread_join(philos[i].thread_id, NULL);
		i++;
	}
	free_and_close(table, philos);
}
