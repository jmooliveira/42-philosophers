/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:39:04 by jemorais          #+#    #+#             */
/*   Updated: 2025/04/23 19:57:04 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.c

#include "philo.h"

int	main(int argc, char **argv)
{
	t_config	*config;

	config = NULL;
	config = ft_calloc(1, sizeof(t_config));
	validate(argc, argv);
	if (!config_args(config, argv))
		exit (UNEXPECTED_ERROR);
	printf("entra no código\n");
	free_and_close(config);
}
	// printf("number_of_philosophers: %d\ntime_to_die: %d\ntime_to_eat: %d\ntime_to_sleep %d\n[number_of_times_each_philosopher_must_eat]: %d\n", config->number_philos, config->time_to_die, config->time_to_eat, config->time_to_sleep, config->number_meals);
