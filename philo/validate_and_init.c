/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_and_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:39:23 by jemorais          #+#    #+#             */
/*   Updated: 2025/05/26 16:56:35 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// validate_and_init.c

#include "philo.h"

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

bool	validate_args(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("Error\nUse: number_of_philosophers time_to_die time_to_eat ");
		printf("time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
		return (false);
	}
	if (!check_args(argv))
	{
		printf("Error\nArguments must be positive integers greather than 0\n");
		return (false);
	}
	return (true);
}

void	init_table(t_table *table, char **argv)
{
	table->number_philos = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		table->number_meals = ft_atol(argv[5]);
	else
		table->number_meals = -1;
	if (table->time_to_die - (table->time_to_eat + table->time_to_sleep) - 1 < 0)
		table->time_to_think = 0;
	else if (table->time_to_die - (table->time_to_eat + table->time_to_sleep) - 1 == 0)
		table->time_to_think = 1;
	else
		table->time_to_think = table->time_to_die - (table->time_to_eat + table->time_to_sleep) - 1;
	pthread_mutex_init(&table->print_lock, NULL);
	pthread_mutex_init(&table->stop_mutex, NULL);
}

bool	init_forks(t_table *table)
{
	int	i;

	table->forks = ft_calloc(table->number_philos, sizeof(pthread_mutex_t));
	if (!table->forks)
		return (false);
	i = 0;
	while (i < table->number_philos)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			return (false);
		i++;
	}
	return (true);
}

bool	init_philos(t_philo **philos, t_table *table)
{
	int	i;

	table->philos = ft_calloc(table->number_philos, sizeof(t_philo));
	if (!table->philos)
		return (false);
	*philos = table->philos;
	table->start_time = get_time_ms();
	i = 0;
	while (i < table->number_philos)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].left_fork = &table->forks[i];
		(*philos)[i].right_fork = &table->forks[(i + 1) % table->number_philos];
		(*philos)[i].last_meal = table->start_time;
		(*philos)[i].meals_eaten = 0;
		(*philos)[i].table = table;
		pthread_mutex_init(&table->philos[i].meal_mutex, NULL);
		i++;
	}
	return (true);
}
