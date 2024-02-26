/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:09:49 by mho               #+#    #+#             */
/*   Updated: 2024/01/29 13:33:25 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void *routine(void *data) {
  t_philo *philo;
	pthread_t monitor_thread;

  philo = (t_philo *)data;
  pthread_create(&monitor_thread, NULL, &monitor, philo);
  while (1) {
    eat(philo);
    sleeping(philo);
    think(philo);
  }
  return (data);
}

void sleeping(t_philo *philo) {
  print_philo(philo, "is sleeping");
  ft_usleep(philo->time_to_sleep);
}

void think(t_philo *philo) { print_philo(philo, "is thinking"); }

void eat(t_philo *philo) {
  if (philo->number_of_philos == 1) {
    ft_usleep(philo->time_to_die);
    return;
  }
  sem_wait(philo->chopsticks);
  print_philo(philo, "has taken a fork");
  sem_wait(philo->chopsticks);
  print_philo(philo, "has taken a fork");
  philo->eating = 1;
  sem_wait(philo->meal);
  print_philo(philo, "is eating");
  philo->last_meal = get_current_time();
  philo->meals_eaten++;
  sem_post(philo->meal);
  ft_usleep(philo->time_to_eat);
  philo->eating = 0;
  sem_post(philo->chopsticks);
  sem_post(philo->chopsticks);
}

