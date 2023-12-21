/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 07:59:38 by mho               #+#    #+#             */
/*   Updated: 2023/12/21 08:31:49 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	innit_split(t_chunk *min, t_chunk *mid, t_chunk *max)
{
	min->size = 0;
	mid->size = 0;
	max->size = 0;
}

void	set_split_target(t_chunk *chunk_to_sort, t_chunk *min, t_chunk *mid,
		t_chunk *max)
{
	if (chunk_to_sort->loc == TOP_A)
	{
		max->loc = BOT_A;
		mid->loc = TOP_B;
		min->loc = BOT_B;
	}
	else if (chunk_to_sort->loc == TOP_B)
	{
		max->loc = TOP_A;
		mid->loc = BOT_A;
		min->loc = BOT_B;
	}
	else if (chunk_to_sort->loc == BOT_A)
	{
		max->loc = TOP_A;
		mid->loc = TOP_B;
		min->loc = BOT_B;
	}
	else if (chunk_to_sort->loc == BOT_B)
	{
		max->loc = TOP_A;
		mid->loc = BOT_A;
		min->loc = TOP_B;
	}
}

void	set_pivots(t_chunk *chunk, int *large_pivot, int *small_pivot,
		int max_val)
{
	*large_pivot = max_val - (1 * chunk->size / 3);
	*small_pivot = max_val - (2 * chunk->size / 3);
	if (chunk->size < 20)
	{
		*large_pivot = max_val - (1 * chunk->size / 2);
		*small_pivot = max_val - chunk->size;
	}
	return ;
}
