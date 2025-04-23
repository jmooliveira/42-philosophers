/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:39:04 by jemorais          #+#    #+#             */
/*   Updated: 2025/04/23 17:52:03 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.c

#include "philo.h"

int	main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("Error\nUse: number_of_philosophers time_to_die time_to_eat ");
		printf("time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
		return (EXIT_ERROR_NUMBER_ARGS);
	}
	if (!check_args(argv))
	{
		printf("Error\nArguments must be positive integers greather than 0\n");
		return (EXIT_NEGATIVE_ARGS);
	}
	printf("entra no código\n");
	return (0);
}
