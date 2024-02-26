/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:01:36 by mho               #+#    #+#             */
/*   Updated: 2024/01/29 13:27:35 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void philo_mutex_init(t_philo *philo, t_data *data) {
  philo->dead = data->dead;
  philo->meal = data->meal;
  philo->write = data->write;
  philo->stop = data->stop;
}

void philo_init(t_philo *philo, t_data *data, int ac, char **av) {
  int i;

  i = -1;
  while (++i < ft_atoi(av[1])) {
    philo[i].id = i;
    philo[i].pid = -1;
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
    philo[i].chopsticks = data->chopsticks;
    philo_mutex_init(&philo[i], data);
  }
}

void data_init(t_data *data, char **av) {
  int number_of_philos;

  number_of_philos = ft_atoi(av[1]);
  data->dead_flag = 0;
  data->philos = malloc(sizeof(t_philo) * number_of_philos);
  data->chopsticks = malloc(sizeof(sem_t) * number_of_philos);
  data->chopsticks = sem_open("chopsticks", O_CREAT, 0600, number_of_philos);
  data->dead = sem_open("dead", O_CREAT, 0600, 1);
  data->meal = sem_open("meal", O_CREAT, 0600, 1);
  data->write = sem_open("write", O_CREAT, 0600, 1);
  data->stop = sem_open("stop", O_CREAT, 0600, 0);
}
