/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:25:30 by mho               #+#    #+#             */
/*   Updated: 2023/11/23 17:00:43 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_one(t_ps *data, t_chunk *chunk)
{
	if (chunk->loc != TOP_A)
		move_elements(data, chunk->loc, TOP_A);
	chunk->size--;
}

void sort_two(t_ps *data, t_chunk *chunk)
{
	if (chunk->loc != TOP_A)
		move_elements(data, chunk->loc, TOP_A);
	if (data->a->arr[data->a->head] > data->a->arr[i_downdown(data->a->head)])
		sa(data);
	chunk->size -= 2;
}

void sort_three(t_ps *data, t_chunk *chunk)
{
	int max;

	max = chunk_max_value(data, chunk);
	if (chunk->loc == TOP_A)
		sort_three_top_a(data, chunk, max);
	else if (chunk->loc == TOP_B)
		sort_three_top_b(data, chunk, max);
	else if (chunk->loc == BOT_A)
		sort_three_bot_a(data, chunk, max);
	else if (chunk->loc == BOT_B)
		sort_three_bot_b(data, chunk, max);
	chunk->size--;
	chunk->loc = TOP_A;
	sort_two(data, chunk);
}

void sort_three_top_a(t_ps *data, t_chunk *chunk, int max)
{
	int i;

	i = data->a->head;
	if (data->a->arr[i] == max)
	{
		sa(data);
		ra(data);
		sa(data);
		rra(data);
	}
	else if (data->a->arr[i_downdown(data->a, i)] == max)
	{
		ra(data);
		sa(data);
		rra(data);
	}
}

void sort_three_top_b(t_ps *data, t_chunk *chunk, int max)
{
	int i;

	pa(data);
	i = data->b->head;
	if (data->b->arr[i] == max)
	{
		pa(data);
		sa(data);
	}
	else if (data->b->arr[i_downdown(data->b, i)] == max)
	{
		sb(data);
		pa(data);
		sa(data);
	}
	else
		pa(data);
	pa(data);
} //redo

void sort_three_bot_a(t_ps *data, t_chunk *chunk, int max)
{
	int i;

	i = data->a->head;
	rra(data);
	rra(data);
	if (data->a->arr[i] == max)
	{
		sa(data);
		rra(data);
	}
	else if (data->a->arr[i_downdown(data->a, i)] == max)
		rra(data);
	else
	{
		pb(data);
		rra(data);
		sa(data);
		pa(data);
	}
}

void sort_three_bot_b(t_ps *data, t_chunk *chunk, int max)
{

}


void sort_four(t_ps *data, t_chunk *chunk)
{
	if (chunk->loc != TOP_A)
		move_elements(data, chunk->loc, TOP_A);
}

void sort_five(t_ps *data, t_chunk *chunk)
{
	if (chunk->loc != TOP_A)
		move_elements(data, chunk->loc, TOP_A);
}

//not part of quick sort

void simple_sort_two(t_ps *data)
{
	if (data->a->arr[0] > data->a->arr[1])
		sa(data);
	return ;
}

void simple_sort_three(t_ps *data)
{
	int first;
	int second;
	int third;

	first = data->a->arr[0];
	second = data->a->arr[1];
	third = data->a->arr[2];
	if (second < first && first < third && third > second) //case 1
		sa(data);
	else if ((third < second && second < first && first > third)
		|| (first < second && second > third && third > first))
	{
		sa(data);
		rra(data);
	}
	else if (first > second && second < third && first > third)
		ra(data);
	else if (first < second && second > third && third < first)
		rra(data);
}

void simple_sort_five(t_ps *data)
{
	while (stack_size(data->a) > 3)
	{
		if (data->a->arr[data->a->head] == 1 || data->a->arr[data->a->head] == 2)
			pb(data);
		else
			ra(data);
	}
	simple_sort_three(data);
	if (data->b->arr[0] > data->b->arr[1])
		rb(data);
	pa(data);
	pa(data);
}
