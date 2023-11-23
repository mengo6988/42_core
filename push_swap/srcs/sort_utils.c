/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 07:59:38 by mho               #+#    #+#             */
/*   Updated: 2023/11/23 15:58:10 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void innit_split(t_split *split)
{
	split->min->size = 0;
	split->mid->size = 0;
	split->max->size = 0;
}

void set_split_target(t_chunk *chunk_to_sort, t_split *split)
{
	if (chunk_to_sort->loc == TOP_A)
	{
		split->max->loc = BOT_A;
		split->mid->loc = TOP_B;
		split->min->loc = BOT_B;
	}
	else if (chunk_to_sort->loc == TOP_B)
	{
		split->max->loc = TOP_A;
		split->mid->loc = BOT_A;
		split->min->loc = BOT_B;
	}
	else if (chunk_to_sort->loc == BOT_A)
	{
		split->max->loc = TOP_A;
		split->mid->loc = TOP_B;
		split->min->loc = BOT_B;
	}
	else if (chunk_to_sort->loc == BOT_B)
	{
		split->max->loc = TOP_A;
		split->mid->loc = BOT_B;
		split->min->loc = TOP_B;
	}
}

int chunk_max_value(t_ps *data, t_chunk *chunk)
{
	int i;
	int max_val;
	int size;
	t_stack *stk;

	if (chunk->loc == TOP_A || chunk->loc == BOT_A)
		stk = data->a;
	else if (chunk->loc == TOP_B || chunk->loc == BOT_B)
		stk = data->b;
	size = chunk->size;
	max_val = 0;
	while (size--)
	{
		if (max_val < stk->arr[i])
			max_val = stk->arr[i];
		if (chunk->loc == TOP_A || chunk->loc == TOP_B)
			i = i_downdown(stk, i);
		else if (chunk->loc == BOT_A || chunk->loc == BOT_B)
			i = i_upup(stk, i);
 	}
	return (max_val);
}

int get_index(t_ps *data, t_chunk *chunk)
{
	int index;

	if (chunk->loc == TOP_A)
		index = data->a->head;
	else if (chunk->loc == BOT_A)
		index = data->a->tail;
	else if (chunk->loc == TOP_B)
		index = data->b->head;
	else if (chunk->loc == BOT_B)
		index = data->b->tail;
	return (index);
}

void	set_pivots(t_chunk *chunk, int *large_pivot, int *small_pivot, int max_val)
{
	*large_pivot = max_val - (1 * chunk->size / 3);
	*small_pivot = max_val - (2 * chunk->size / 3);
	return ;
}
int	chunk_value(t_ps *data, t_chunk *chunk)
{
	t_stack *stk;
	int		i;

	if (chunk->loc == TOP_A || chunk->loc == BOT_A)
		stk = data->a;
	else if (chunk->loc == TOP_B || chunk->loc == BOT_B)
		stk = data->b;
	i = get_index(data, chunk);
	return(stk->arr[i]);
}

void	move_elements(t_ps *data, enum eloc *from, enum eloc *to)
{
	if (from == TOP_A)
		move_from_top_a(data, to);
	else if (from == TOP_B)
		move_from_top_b(data, to);
	else if (from == BOT_A)
		move_from_bot_a(data, to);
	else if (from == BOT_B)
		move_from_bot_b(data, to);
}

void move_from_top_a(t_ps *data, enum eloc *to)
{
	if (to == TOP_B)
		pb(data);
	else if (to == BOT_A)
		ra(data);
	else if (to == BOT_B)
	{
		pb(data);
		rb(data);
	}
}

void move_from_top_b(t_ps *data, enum eloc *to)
{
	if (to == TOP_A)
		pa(data);
	else if (to == BOT_B)
		rb(data);
	else if (to == BOT_A)
	{
		pa(data);
		ra(data);
	}
}

void move_from_bot_b(t_ps *data, enum eloc *to)
{
	if (to == TOP_B)
		rrb(data);
	else if (to == TOP_A)
	{
		rrb(data);
		pa(data);
	}
	else if (to == BOT_A)
	{
		rrb(data);
		pa(data);
		ra(data);
	}
}

void move_from_bot_a(t_ps *data, enum eloc *to)
{
	if (to == TOP_B)
	{
		rra(data);
		pb(data);
	}
	else if (to == TOP_A)
		rra(data);
	else if (to == BOT_B)
	{
		rra(data);
		pb(data);
		rb(data);
	}
}
