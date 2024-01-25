/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:55:42 by mho               #+#    #+#             */
/*   Updated: 2024/01/24 13:36:45 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_args(char **av)
{
	int i;
	int j;

	i = -1;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
		}
	}
	return (0);
}

int main(int ac, char **av)
{
	t_data data;

	if (ac < 4 || ac > 5 || check_args(av))
		return (1);
	data_init(&data, av);
	philo_init(data.philos, &data, ac, av);
}
