/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:28:25 by mho               #+#    #+#             */
/*   Updated: 2024/01/24 14:01:11 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
//usleep
# include <unistd.h>
# include <stdlib.h>
//threading functions
# include <pthread.h>
//gettimeofday
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t	thread;
	int	id;
	//dk if need
	int eating;
	int meals_eaten;
	size_t last_meal;
	size_t time_to_die;
	size_t time_to_eat;
	size_t time_to_sleep;
	size_t start_time;
	pthread_mutex_t *right_chopstick;
	pthread_mutex_t *left_chopstick;
	int number_of_philos;
	int number_times_to_eat;
}		t_philo;

typedef struct s_data
{
	pthread_mutex_t dead;
	pthread_mutex_t meal;
	pthread_mutex_t write;
	t_philo *philos;
	pthread_mutex_t *chopticks;
	int	dead_flag;
}	t_data;

#endif
