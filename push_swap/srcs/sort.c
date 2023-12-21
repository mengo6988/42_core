/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 07:29:12 by mho               #+#    #+#             */
/*   Updated: 2023/12/21 08:39:52 by mho              ###   ########.fr       */
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
	t_chunk	main_chunk;

	main_chunk.loc = TOP_A;
	main_chunk.size = data->a->size;
	rec_sort(data, &main_chunk);
}

void	rec_sort(t_ps *data, t_chunk *chunk_to_sort)
{
	t_split	split;

	loc_opti(data, chunk_to_sort);
	if (chunk_to_sort->size < 4)
	{
		if (chunk_to_sort->size == 1)
			sort_one(data, chunk_to_sort);
		else if (chunk_to_sort->size == 2)
			sort_two(data, chunk_to_sort);
		else if (chunk_to_sort->size == 3)
			sort_three(data, chunk_to_sort);
		return ;
	}
	split_chunk(data, chunk_to_sort, &split);
	rec_sort(data, &split.max);
	rec_sort(data, &split.mid);
	rec_sort(data, &split.min);
}

void	split_chunk(t_ps *data, t_chunk *chunk_to_sort, t_split *split)
{
	int	large_pivot;
	int	small_pivot;
	int	max_val;
	int	cur_val;

	innit_split(&split->min, &split->mid, &split->max);
	set_split_target(chunk_to_sort, &split->min, &split->mid, &split->max);
	max_val = chunk_max_value(data, chunk_to_sort);
	set_pivots(chunk_to_sort, &large_pivot, &small_pivot, max_val);
	while (chunk_to_sort->size--)
	{
		cur_val = chunk_value(data, chunk_to_sort);
		if (cur_val > large_pivot)
			split->max.size += move_elements(data, chunk_to_sort->loc,
					split->max.loc);
		else if (cur_val > small_pivot)
			split->mid.size += move_elements(data, chunk_to_sort->loc,
					split->mid.loc);
		else
			split->min.size += move_elements(data, chunk_to_sort->loc,
					split->min.loc);
	}
}

void	loc_opti(t_ps *data, t_chunk *to_sort)
{
	if (stack_size(data->a) == to_sort->size && to_sort->loc == BOT_A)
		to_sort->loc = TOP_A;
	if (stack_size(data->b) == to_sort->size && to_sort->loc == BOT_B)
		to_sort->loc = TOP_B;
	return ;
}
