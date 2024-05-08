/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:55:42 by mho               #+#    #+#             */
/*   Updated: 2024/01/29 13:33:05 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int check_args(char **av) {
  int i;
  int j;

  i = -1;
  while (av[++i]) {
    j = -1;
    while (av[i][++j]) {
      if (av[i][j] < '0' || av[i][j] > '9')
        return (1);
    }
  }
  return (0);
}
/*
void test_philos(t_data *data) {
  printf("data dead= %p\n", &data->dead);
  printf("data meal= %p\n", &data->meal);
  printf("data write = %p\n", &data->write);
  printf("\n");
  for (int i = 0; i < data->philos->number_of_philos; i++) {
    printf("data philos= %p\n", &data->philos[i]);
    printf("philos id= %i\n", data->philos[i].id);
    printf("philos eating= %i\n", data->philos[i].eating);
    printf("philos meals_eaten= %i\n", data->philos[i].meals_eaten);
    printf("philos lastmeal= %zu\n", data->philos[i].last_meal);
    printf("philos time to die= %zu\n", data->philos[i].time_to_die);
    printf("philos time to eat= %zu\n", data->philos[i].time_to_eat);
    printf("philos time to sleep= %zu\n", data->philos[i].time_to_sleep);
    printf("philos time start= %zu\n", data->philos[i].start_time);
    if (i == data->philos[i].number_of_philos - 1)
      printf("data chopsticks (%p) vs right chopstick (%p)\n",
             &data->chopsticks[0], data->philos[i].right_chopstick);
    else
      printf("data chopsticks (%p) vs right chopstick (%p)\n",
             &data->chopsticks[i + 1], data->philos[i].right_chopstick);
    printf("data chopsticks (%p) vs left chopstick (%p)\n",
           &data->chopsticks[i], data->philos[i].left_chopstick);
    printf("philos number of philos= %u\n",
    data->philos[i].number_of_philos); printf("philos number of times to eat
    = %i\n",
           data->philos[i].number_times_to_eat);
    printf("data dead(philo) = %i\n", *data->philos[i].dead_flag);
    printf("data dead (%p) vs philo dead (%p)\n", &data->dead,
           data->philos[i].dead);
    printf("data meal (%p) vs philo meal (%p)\n", &data->meal,
           data->philos[i].meal);
    printf("data write (%p) vs philo write (%p)\n", &data->write,
           data->philos[i].write);
    printf("\n");
  }
}
*/

int main(int ac, char **av) {
  t_data data;

  if (ac < 5 || ac > 6 || !check_args(av))
    return (1);
  data_init(&data, av);
  philo_init(data.philos, &data, ac, av);
  fork_init(&data);
  sem_wait(data.stop);
  ft_exit(&data, NULL);
  return (0);
}
