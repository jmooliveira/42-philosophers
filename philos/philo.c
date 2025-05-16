/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:39:04 by jemorais          #+#    #+#             */
/*   Updated: 2025/05/16 16:06:38 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.c

#include "philo.h"

bool	start_threads(t_philo *philos, t_table *table)
{
	int	i;

	i = 0;
	while (i < table->number_philos)
	{
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

void	join_thread(t_table *table, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < table->number_philos)
	{
		pthread_join(philos[i].thread_id, NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_table		*table;
	t_philo		*philos;
	pthread_t	monitor_thread;

	table = ft_calloc(1, sizeof(t_table));
	if (!validate_args(argc, argv))
		exit (EXIT_ERROR);
	philos = NULL;
	init_table(table, argv);
	if (!init_forks(table) || !init_philo(&philos, table))
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
	pthread_create(&monitor_thread, NULL, monitor, philos);
	pthread_join(monitor_thread, NULL);
	join_thread(table, philos);
	free_and_close(table, philos);
	exit(0);
}
