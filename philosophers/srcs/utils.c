/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:14:34 by mho               #+#    #+#             */
/*   Updated: 2024/01/28 14:51:11 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_atoi(char *s)
{
	int i;
	int pos;
	int res;

	i = 0;
	pos = 1;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] < 14))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i++] == '-')
			pos = -1;
	}
	res = 0;
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
	{
		res *= 10;
		res += (s[i++] - '0') * pos;
	}
	return (res);
}

size_t get_current_time(void)
{
	struct timeval time;

	if (gettimeofday(&time, NULL) != 0)
		printf("time error\n");
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	ft_usleep(size_t duration)
{
	size_t start;

	start = get_current_time();
	while (get_current_time() - start < duration)
		usleep(500);
	return (0);
}

void ft_exit(t_data *data, char *error_message)
{
	int i;

	printf("%s", error_message);
	i = -1;
	while (++i < data->philos[0].number_of_philos)
		pthread_mutex_destroy(&data->chopsticks[i]);
	pthread_mutex_destroy(&data->dead);
	pthread_mutex_destroy(&data->meal);
	pthread_mutex_destroy(&data->write);
	free(data->philos);
	free(data->chopsticks);
}

void	print_philo(t_philo *philo, char *msg)
{
	size_t current_time;

	pthread_mutex_lock(philo->write);
	current_time = get_current_time() - philo->start_time;
	if (!dead(philo))
		printf("%zu %i %s\n", current_time, philo->id, msg);
	pthread_mutex_unlock(philo->write);
}
