/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:01:36 by mho               #+#    #+#             */
/*   Updated: 2024/01/28 16:56:54 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_mutex_init(t_philo *philo, t_data *data)
{
	philo->dead = &data->dead;
	philo->meal = &data->meal;
	philo->write = &data->write;
	philo->dead_flag = &data->dead_flag;
}

void	philo_init(t_philo *philo, t_data *data, int ac, char **av)
{
	int i;

	i = -1;
	while (++i < ft_atoi(av[1]))
	{
		philo[i].id = i;
		philo[i].eating = 0;
		philo[i].meals_eaten = 0;
		philo[i].last_meal = get_current_time();
		philo[i].start_time = get_current_time();
		philo[i].time_to_die = ft_atoi(av[2]);
		philo[i].time_to_eat = ft_atoi(av[3]);
		philo[i].time_to_sleep = ft_atoi(av[4]);
		philo[i].number_of_philos = ft_atoi(av[1]);
		if (ac == 6)
			philo[i].number_times_to_eat = ft_atoi(av[5]);
		else
			philo[i].number_times_to_eat = -1;
		philo[i].left_chopstick = &data->chopsticks[i];
		if (i == philo[i].number_of_philos - 1)
			philo[i].right_chopstick = &data->chopsticks[0];
		else
			philo[i].right_chopstick = &data->chopsticks[i + 1];
		philo_mutex_init(&philo[i], data);
	}
}

void	data_init(t_data *data, char **av)
{
	int number_of_philos;
	int i;

	number_of_philos = ft_atoi(av[1]);
	data->dead_flag = 0;
	data->philos = malloc(sizeof(t_philo) * number_of_philos);
	data->chopsticks = malloc(sizeof(pthread_mutex_t) * number_of_philos);
	data->dead_flag = 0;
	i = -1;
	while (++i < number_of_philos)
		pthread_mutex_init(&data->chopsticks[i], NULL);
	pthread_mutex_init(&data->dead, NULL);
	pthread_mutex_init(&data->meal, NULL);
	pthread_mutex_init(&data->write, NULL);
}
