/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 08:47:17 by mho               #+#    #+#             */
/*   Updated: 2023/12/05 09:27:57 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (chunk->loc == TOP_A || chunk->loc == TOP_B)
		i = stk->head;
	else if (chunk->loc == BOT_A || chunk->loc == BOT_B)
		i = stk->tail;
	while (size-- > 0)
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
	else
		index = data->b->tail;
	return (index);
}

int	chunk_value(t_ps *data, t_chunk *chunk)
{
	t_stack *stk;
	int		i;

	if (chunk->loc == TOP_A || chunk->loc == BOT_A)
		stk = data->a;
	else
		stk = data->b;
	i = get_index(data, chunk);
	return(stk->arr[i]);
}
