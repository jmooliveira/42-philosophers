/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:38:57 by jemorais          #+#    #+#             */
/*   Updated: 2025/05/06 17:21:07 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// philo.h

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define EXIT_ERROR_NUMBER_ARGS 1
# define EXIT_NEGATIVE_ARGS 2
# define UNEXPECTED_ERROR 3

typedef struct s_table t_table;

typedef struct s_philo
{
	int				id;
	int				meals_eat;
	pthread_t		thread_id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_table			*table;
}	t_philo;

typedef struct s_table
{
	int				number_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_meals;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	long			start_time;
}	t_table;

// validate_and_init.c
bool		check_args(char **argv);
bool		init_args(t_table *table, char **argv);
void		validate(int argc, char **argv);
bool		init_table(t_table *table);
t_philo		*init_philo(t_philo *philo);

// utils.c
bool	ft_isdigit(char c);
long	ft_atol(char *argv);
void	*ft_calloc(size_t nmemb, size_t size);

// free.c
void	free_and_close(t_table *table);

#endif
