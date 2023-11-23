/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 07:29:12 by mho               #+#    #+#             */
/*   Updated: 2023/11/23 15:30:00 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_ps *data)
{
	if (data->a->size == 1)
		return ;
	else if (data->a->size == 2)
		simple_sort_two(data);
	else if (data->a->size == 3)
		simple_sort_three(data);
	else if (data->a->size <= 5)
		simple_sort_five(data);
	else
		chunk_sort(data);
}

void	chunk_sort(t_ps *data)
{
	t_chunk *main_chunk;

	main_chunk->loc = TOP_A;
	main_chunk->index = 0;
	main_chunk->size = data->a->size;
	rec_sort(data, main_chunk);
}

void rec_sort(t_ps *data, t_chunk *chunk_to_sort)
{
	t_split	*split;

	if (chunk_to_sort->size < 5)
	{

		return ;
	}
	split_chunk(data, chunk_to_sort, split);
	rec_sort(data, &split->max);
	rec_sort(data, &split->mid);
	rec_sort(data, &split->min);
}

void	split_chunk(t_ps *data, t_chunk *chunk_to_sort, t_split *split)
{
	int	large_pivot;
	int	small_pivot;
	int max_val;
	int cur_val;

	innit_split(split);
	set_split_target(chunk_to_sort, split);
	max_val = chunk_max_value(data, chunk_to_sort);
	set_pivots(chunk_to_sort, &large_pivot, &small_pivot, max_val);
	while (chunk_to_sort->size--)
	{
		cur_val = chunk_value(data, chunk_to_sort);
		if (cur_val > large_pivot)
			move_elements(data, chunk_to_sort->loc, split->max->loc);
		else if (cur_val > small_pivot)
			move_elements(data, chunk_to_sort->loc, split->mid->loc);
		else
			move_elements(data, chunk_to_sort->loc, split->min->loc);
	}
}
