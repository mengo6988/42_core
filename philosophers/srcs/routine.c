/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:09:49 by mho               #+#    #+#             */
/*   Updated: 2024/01/29 10:03:50 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	if (philo->id % 2 >= 0)
		ft_usleep(1);
	while (dead(philo) == 0)
	{
		eat(philo);
		sleeping(philo);
		think(philo);
	}
	return (data);
}

void	sleeping(t_philo *philo)
{
	print_philo(philo, "is sleeping");
	ft_usleep(philo->time_to_sleep);
}
void	think(t_philo *philo)
{
	print_philo(philo, "is thinking");
}
void	eat(t_philo *philo)
{
	if (philo->number_of_philos == 1)
	{
		ft_usleep(philo->time_to_die);
		return ;
	}
	pthread_mutex_lock(philo->left_chopstick);
	print_philo(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_chopstick);
	print_philo(philo, "has taken a fork");
	philo->eating = 1;
	pthread_mutex_lock(philo->meal);
	print_philo(philo, "is eating");
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal);
	ft_usleep(philo->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->left_chopstick);
	pthread_mutex_unlock(philo->right_chopstick);
}

int	dead(t_philo *philo)
{
	int res;

	pthread_mutex_lock(philo->dead);
	if (*philo->dead_flag == 1)
		res = 1;
	else
		res = 0;
	pthread_mutex_unlock(philo->dead);
	return (res);
}
