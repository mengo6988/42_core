/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:28:28 by mho               #+#    #+#             */
/*   Updated: 2024/01/29 13:29:29 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thread_init(t_data *data)
{
	int			i;
	pthread_t	monitor_thread;

	if (pthread_create(&monitor_thread, NULL, &monitor, data->philos))
		ft_exit(data, "monitor thread error");
	i = -1;
	while (++i < data->philos[0].number_of_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL, &routine,
				&data->philos[i]))
			ft_exit(data, "philo thread error");
	}
	if (pthread_join(monitor_thread, NULL))
		ft_exit(data, "monitor join error");
	i = -1;
	while (++i < data->philos[0].number_of_philos)
	{
		if (pthread_join(data->philos[i].thread, NULL))
			ft_exit(data, "philo join error");
	}
	return ;
}

void	*monitor(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (1)
	{
		if (are_they_dead(philo) || are_they_full(philo))
			break ;
	}
	return (ptr);
}

int	are_they_dead(t_philo *philo)
{
	int	i;
	int	is_dead;

	i = -1;
	is_dead = 0;
	while (++i < philo[0].number_of_philos)
	{
		pthread_mutex_lock(philo[i].meal);
		if ((get_current_time() - philo[i].last_meal > philo[i].time_to_die
				&& philo[i].eating == 0))
			is_dead = 1;
		pthread_mutex_unlock(philo[i].meal);
		if (is_dead == 1)
		{
			pthread_mutex_lock(philo[i].dead);
			*philo[i].dead_flag = 1;
			pthread_mutex_lock(philo[i].write);
			printf("%zu philo %i died\n", get_current_time()
				- philo[i].start_time, philo[i].id);
			pthread_mutex_unlock(philo[i].write);
			pthread_mutex_unlock(philo[i].dead);
			return (1);
		}
	}
	return (0);
}

int	are_they_full(t_philo *philo)
{
	int	i;
	int	full;

	i = -1;
	full = 0;
	while (++i < philo[0].number_of_philos)
	{
		pthread_mutex_lock(philo[i].meal);
		if (philo[i].meals_eaten >= philo[i].number_times_to_eat
			&& philo[i].number_times_to_eat > 0)
			full++;
		pthread_mutex_unlock(philo[i].meal);
	}
	if (full == philo[0].number_of_philos)
	{
		pthread_mutex_lock(philo[0].dead);
		*philo[0].dead_flag = 1;
		pthread_mutex_unlock(philo[0].dead);
		return (1);
	}
	return (0);
}

// void philo_thread_init(t_philo *philo)
// {
// 	pthread_mutex_lock(philo->init);
// 	*philo->init_flag += 1;
// 	philo->id = *philo->init_flag;
// 	pthread_mutex_unlock(philo->init);
// 	while (1)
// 	{
// 		pthread_mutex_lock(philo->init);
// 		if (*philo->init_flag == philo->number_of_philos - 1)
// 		{
// 			philo->start_time = get_current_time();
// 			pthread_mutex_unlock(philo->init);
// 			break ;
// 		}
// 		pthread_mutex_unlock(philo->init);
// 	}
// 	return ;

// }
