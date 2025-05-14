/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:38:57 by jemorais          #+#    #+#             */
/*   Updated: 2025/05/14 15:50:57 by jemorais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// philo.h

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define EXIT_ERROR 1
# define INIT_ERROR 2

typedef struct s_table	t_table;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			last_meal;
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
	long			start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	bool			stop;
	pthread_mutex_t	stop_mutex;
}	t_table;

// validate_and_init.c
bool	check_args(char **argv);
bool	validate_args(int argc, char **argv);
void	init_table(t_table *table, char **argv);
bool	init_forks(t_table *table);
bool	init_philo(t_philo **philos, t_table *table);

// utils.c
bool	ft_isdigit(char c);
long	ft_atol(char *argv);
void	*ft_calloc(size_t nmemb, size_t size);

// philo.c
bool	start_threads(t_philo *philos, t_table *table);

// monitor.c
void	*monitor(void *arg);

// routine.c
long	get_time_ms(void);
void	print_action(t_philo *philo, char *msg);
void	eat(t_philo *philo);
void	*philo_routine(void *arg);

// free.c
void	free_and_close(t_table *table, t_philo *philos);

#endif
