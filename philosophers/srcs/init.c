/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:01:36 by mho               #+#    #+#             */
/*   Updated: 2024/01/24 14:28:42 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init(t_philo *philo, t_data *data, int ac, char **av)
{
	int i;

	i = -1;
	while (i < av[1])
	{
		philo[i].id = i;
		philo[i].meals_eaten = 0;
		philo[i].last_meal = get_current_time();

	}
}

void	data_init(t_data *data, char **av)
{
	int number_of_philos;
	int i;

	number_of_philos = ft_atoi(av[i]);
	data->dead_flag = 0;
	data->philos = malloc(sizeof(t_philo) * number_of_philos);
	data->chopticks = malloc(sizeof(pthread_mutex_t) * number_of_philos);
	i = -1;
	while (++i < number_of_philos)
		pthread_mutex_init(&data->chopticks[i], NULL);
	pthread_mutex_init(&data->dead, NULL);
	pthread_mutex_init(&data->meal, NULL);
	pthread_mutex_init(&data->write, NULL);
}
