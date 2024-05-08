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

#include "philo_bonus.h"

void	fork_init(t_data *data)
{
    int i;
	int status;

    i = -1;
    while (++i < data->philos[0].number_of_philos)
    {
        data->philos[i].pid = fork();
        if (data->philos[i].pid == 0)
        {
            routine(data->philos + i);
            exit(0);
        }
        ft_usleep(1);
    }
	i = -1;
	while (++i < data->philos[0].number_of_philos)
		wait(&status);
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
	sem_post(philo->stop);
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
		sem_wait(philo[i].meal);
		if ((get_current_time() - philo[i].last_meal > philo[i].time_to_die
				&& philo[i].eating == 0))
			is_dead = 1;
		sem_post(philo[i].meal);
		if (is_dead == 1)
		{
			sem_wait(philo[i].dead);
			sem_wait(philo[i].write);
			printf("%zu philo %i died\n", get_current_time()
				- philo[i].start_time, philo[i].id);
			sem_post(philo[i].write);
			sem_post(philo[i].dead);
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
		sem_wait(philo[i].meal);
		if (philo[i].meals_eaten >= philo[i].number_times_to_eat
			&& philo[i].number_times_to_eat > 0)
			full++;
		sem_post(philo[i].meal);
	}
	if (full == philo[0].number_of_philos)
		return (1);
	return (0);
}

// void philo_fork_init(t_philo *philo)
// {
// 	sem_wait(philo->init);
// 	*philo->init_flag += 1;
// 	philo->id = *philo->init_flag;
// 	sem_post(philo->init);
// 	while (1)
// 	{
// 		sem_wait(philo->init);
// 		if (*philo->init_flag == philo->number_of_philos - 1)
// 		{
// 			philo->start_time = get_current_time();
// 			sem_post(philo->init);
// 			break ;
// 		}
// 		sem_post(philo->init);
// 	}
// 	return ;

// }
