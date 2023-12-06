/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:59:52 by mho               #+#    #+#             */
/*   Updated: 2023/12/05 21:43:37 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_ps *data;

	data = malloc(sizeof(t_ps));
	init_ps(data, ac);
	fill_stack(data->a, ac, av);
	sort(data);
	print_op(data->op);
	// printf("after---------------------------------\n");
	// int i = data->a->head;
	// for (int count = 0; count < data->a->size; count++)
	// {

	// 	printf("%i\n", data->a->arr[i]);
	// 	i = i_downdown(data->a, i);
	// }
	free(data);
	return (0);
	// system("leaks push_swap");
}

// int main(int ac, char **av) {
// 	t_ps *data;
// 	data = malloc(sizeof(t_ps));
// 	init_ps(data, ac);
// 	fill_stack(data->a, ac, av);
// 	int i;
// 	int j;
// 	printf("before\n");
// 	i = data->a->head;
// 	j = data->b->head;
// 	for (int count = 0; count < data->a->size; count++)
// 	{
// 		printf("a: %i, b: %i\n", data->a->arr[i], data->b->arr[j]);
// 		i = i_downdown(data->a, i);
// 		j = i_downdown(data->b, j);
// 	}
// 	printf("ahead = %i, atail = %i\n", data->a->head, data->a->tail);
// 	printf("bhead = %i, btail = %i\n", data->b->head, data->b->tail);
// 	ra(data);
// 	printf("pb\n");
// 	i = data->a->head;
// 	j = data->b->head;
// 	for (int count = 0; count < data->a->size; count++)
// 	{
// 		printf("a: %i, b: %i\n", data->a->arr[i], data->b->arr[j]);
// 		i = i_downdown(data->a, i);
// 		j = i_downdown(data->b, j);
// 	}
// 	printf("ahead = %i, atail = %i\n", data->a->head, data->a->tail);
// 	printf("bhead = %i, btail = %i\n", data->b->head, data->b->tail);
// 	ra(data);
// 	printf("pb\n");
// 	i = data->a->head;
// 	j = data->b->head;
// 	for (int count = 0; count < data->a->size; count++)
// 	{
// 		printf("a: %i, b: %i\n", data->a->arr[i], data->b->arr[j]);
// 		i = i_downdown(data->a, i);
// 		j = i_downdown(data->b, j);
// 	}
// 	printf("ahead = %i, atail = %i\n", data->a->head, data->a->tail);
// 	printf("bhead = %i, btail = %i\n", data->b->head, data->b->tail);
// 	ra(data);
// 	printf("pb\n");
// 	i = data->a->head;
// 	j = data->b->head;
// 	for (int count = 0; count < data->a->size; count++)
// 	{
// 		printf("a: %i, b: %i\n", data->a->arr[i], data->b->arr[j]);
// 		i = i_downdown(data->a, i);
// 		j = i_downdown(data->b, j);
// 	}
// 	pa(data);
// 	pa(data);
// 	pa(data);
// 	printf("pa 3 times\n");
// 	i = data->a->head;
// 	j = data->b->head;
// 	for (int count = 0; count < data->a->size; count++)
// 	{
// 		printf("a: %i, b: %i\n", data->a->arr[i], data->b->arr[j]);
// 		i = i_downdown(data->a, i);
// 		j = i_downdown(data->b, j);
// 	}
// 	// printf("ahead = %i, atail = %i\n", data->a->head, data->a->tail);
// 	// printf("bhead = %i, btail = %i\n", data->b->head, data->b->tail);

// 	printf("asize = %i, bsize = %i\n", data->a->size, data->b->size);
// 	printf("ahead = %i, atail = %i\n", data->a->head, data->a->tail);
// 	printf("bhead = %i, btail = %i\n", data->b->head, data->b->tail);
// }
