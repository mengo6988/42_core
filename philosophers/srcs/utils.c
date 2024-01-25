/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:14:34 by mho               #+#    #+#             */
/*   Updated: 2024/01/24 14:16:13 by mho              ###   ########.fr       */
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
		res += s[i++] - '0';
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

void	ft_usleep(size_t duration)
{
	size_t start;

	start = get_current_time();
	while (get_current_time() - start < duration)
		usleep(500);
	return (0);
}
