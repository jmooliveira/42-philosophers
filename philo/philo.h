/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:38:57 by jemorais          #+#    #+#             */
/*   Updated: 2025/06/11 15:45:16 by jemorais         ###   ########.fr       */
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
	pthread_mutex_t	meal_mutex;
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
	int				time_to_think;
	long			start_time;
	bool			stop;
	int				number_meals;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	stop_mutex;
	t_philo			*philos;
}	t_table;

// validate_and_init.c
bool	check_args(char **argv);
bool	validate_args(int argc, char **argv);
void	init_table(t_table *table, char **argv);
bool	init_forks(t_table *table);
bool	init_philos(t_philo **philos, t_table *table);

// utils.c
bool	ft_isdigit(char c);
long	ft_atol(char *argv);
void	*ft_calloc(size_t nmemb, size_t size);

// philo.c
bool	start_threads(t_philo *philos, t_table *table);
void	join_thread(t_table *table, t_philo *philos);

// monitor.c
void	*monitor(void *arg);
void	died(t_table *table, t_philo *philos, long time_now, int i);
bool	check_stop_condition(t_philo *philo);
bool	monitor_philos(t_table *table, t_philo *philos);

// monitor_utils.c
long	get_time_ms(void);
void	print_action(t_philo *philo, char *msg);
bool	check_philo_death(t_philo *philo, t_table *table,
			long time_now, int index);
bool	all_philos_ate(t_table *table, t_philo *philos);

// routine.c
void	*philo_routine(void *arg);
bool	take_forks(t_philo *philo);
void	eat(t_philo *philo);
void	drop_forks(t_philo *philo);
void	sleep_think(t_philo *philo);

//routine_utils.c
void	philo_loop(t_philo *philo);
bool	take_fork_even(t_philo *philo);
bool	take_fork_odd(t_philo *philo);

// free.c
void	free_and_close(t_table *table, t_philo *philos);
void	ft_free(t_table **table);

#endif
