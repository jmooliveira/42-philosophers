/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_and_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:39:23 by jemorais          #+#    #+#             */
/*   Updated: 2025/05/06 17:20:49 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// validate.c

#include "philo.h"

void	validate(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("Error\nUse: number_of_philosophers time_to_die time_to_eat ");
		printf("time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
		exit (EXIT_ERROR_NUMBER_ARGS);
	}
	if (!check_args(argv))
	{
		printf("Error\nArguments must be positive integers greather than 0\n");
		exit (EXIT_NEGATIVE_ARGS);
	}
}

bool	check_args(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][0] == '-')
			return (false);
		if (argv[i][0] == '+')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (false);
			j++;
		}
		if (ft_atol(argv[i]) == 0 || ft_atol(argv[i]) > INT_MAX)
			return (false);
		i++;
	}
	return (true);
}

bool	init_args(t_table *table, char **argv)
{
	table->number_philos = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		table->number_meals = ft_atol(argv[5]);
	else
		table->number_meals = -1;
	return (true);
}

bool	init_table(t_table *table)
{
	int	i;

	table->forks = malloc(sizeof(pthread_mutex_t) *table->number_philos);
	if(!table->forks)
		return (false);
	i = 0;
	while (i < table->number_philos)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
				return (false);
			i++;
	}
	if (pthread_mutex_init(&table->print_lock, NULL) != 0)
		return (false);
	return (true);
}

t_philo	*init_philo(t_philo *philo)
{
	(void) *philo;
	return (philo);
}
