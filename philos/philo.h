/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:38:57 by jemorais          #+#    #+#             */
/*   Updated: 2025/04/23 19:53:16 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// philo.h

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>

# define EXIT_ERROR_NUMBER_ARGS 1
# define EXIT_NEGATIVE_ARGS 2
# define UNEXPECTED_ERROR 3

typedef struct s_config
{
	int	number_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_meals;
}	t_config;

// numbers each meal == -1 se não tiver argumento.

bool	check_args(char **argv);
bool	config_args(t_config *config, char **argv);
void	validate(int argc, char **argv);

bool	ft_isdigit(char c);
long	ft_atol(char *argv);
void	*ft_calloc(size_t nmemb, size_t size);

void	free_and_close(t_config *config);

#endif
