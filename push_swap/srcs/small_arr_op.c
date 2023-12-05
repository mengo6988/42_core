/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_arr_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 08:39:31 by mho               #+#    #+#             */
/*   Updated: 2023/12/05 13:36:44 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_one(t_ps *data, t_chunk *chunk)
{
	if (chunk->loc != TOP_A)
		move_elements(data, chunk->loc, TOP_A);
	chunk->size -= 1;
}

void sort_two(t_ps *data, t_chunk *chunk)
{
	if (chunk->loc != TOP_A)
	{
		move_elements(data, chunk->loc, TOP_A);
		move_elements(data, chunk->loc, TOP_A);
	}
	if (data->a->arr[data->a->head] > data->a->arr[i_downdown(data->a, data->a->head)])
		sa(data);
	chunk->size -= 2;
}
