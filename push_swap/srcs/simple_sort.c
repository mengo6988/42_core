/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:25:30 by mho               #+#    #+#             */
/*   Updated: 2023/12/22 09:21:13 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort_two(t_ps *data)
{
	if (data->a->arr[0] > data->a->arr[1])
		sa(data);
	return ;
}

void	simple_sort_three(t_ps *data)
{
	int	first;
	int	second;
	int	third;

	second = i_downdown(data->a, data->a->head);
	third = i_downdown(data->a, second);
	first = data->a->arr[data->a->head];
	second = data->a->arr[second];
	third = data->a->arr[third];
	if (second < first && first < third && third > second)
		sa(data);
	else if (third < second && second < first && first > third)
	{
		sa(data);
		rra(data);
	}
	else if (first < second && second > third && third > first)
	{
		sa(data);
		ra(data);
	}
	else if (first > second && second < third && first > third)
		ra(data);
	else if (first < second && second > third && third < first)
		rra(data);
}

void	simple_sort_five(t_ps *data)
{
	while (stack_size(data->a) >= 4 && is_sorted(data->a) == 0)
	{
		if (data->a->arr[data->a->head] == 1
			|| (data->a->arr[data->a->head] == 2 && data->a->size == 5))
			pb(data);
		else
			ra(data);
	}
	simple_sort_three(data);
	if (data->b->arr[data->b->head] < data->b->arr[i_downdown(data->b,
				data->b->head)])
		rb(data);
	pa(data);
	pa(data);
}
