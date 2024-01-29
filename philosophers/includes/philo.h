/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:28:25 by mho               #+#    #+#             */
/*   Updated: 2024/01/29 13:28:03 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
// usleep
# include <stdlib.h>
# include <unistd.h>
// threading functions
# include <pthread.h>
// gettimeofday
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	pthread_mutex_t	*right_chopstick;
	pthread_mutex_t	*left_chopstick;
	int				number_of_philos;
	int				number_times_to_eat;
	int				*dead_flag;
	int				*init_flag;
	pthread_mutex_t	*dead;
	pthread_mutex_t	*meal;
	pthread_mutex_t	*write;
	pthread_mutex_t	*init;
}					t_philo;

typedef struct s_data
{
	pthread_mutex_t	dead;
	pthread_mutex_t	meal;
	pthread_mutex_t	write;
	pthread_mutex_t	init;
	t_philo			*philos;
	pthread_mutex_t	*chopsticks;
	int				dead_flag;
	int				init_flag;
}					t_data;

// main
int					check_args(char **av);
void				test_philos(t_data *data);

// init
void				philo_mutex_init(t_philo *philo, t_data *data);
void				philo_init(t_philo *philo, t_data *data, int ac, char **av);
void				data_init(t_data *data, char **av);

// routine
void				*routine(void *data);
void				sleeping(t_philo *philo);
void				think(t_philo *philo);
void				eat(t_philo *philo);
int					dead(t_philo *philo);

// thread
void				thread_init(t_data *data);
void				*monitor(void *ptr);
int					are_they_dead(t_philo *philo);
int					are_they_full(t_philo *philo);
// void philo_thread_init(t_philo *philo);

// utils
int					ft_atoi(char *s);
size_t				get_current_time(void);
int					ft_usleep(size_t duration);
void				ft_exit(t_data *data, char *error_message);
void				print_philo(t_philo *philo, char *msg);

#endif
