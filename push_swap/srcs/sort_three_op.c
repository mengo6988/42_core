/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 08:41:19 by mho               #+#    #+#             */
/*   Updated: 2023/12/21 08:30:18 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_ps *data, t_chunk *chunk)
{
	int	max;

	max = chunk_max_value(data, chunk);
	if (chunk->loc == TOP_A)
		sort_three_top_a(data, max);
	else if (chunk->loc == TOP_B)
		sort_three_top_b(data, max);
	else if (chunk->loc == BOT_A)
		sort_three_bot_a(data, max);
	else if (chunk->loc == BOT_B)
		sort_three_bot_b(data, max);
	chunk->size--;
	chunk->loc = TOP_A;
	sort_two(data, chunk);
}

void	sort_three_top_a(t_ps *data, int max)
{
	int	i;

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

void	sort_three_top_b(t_ps *data, int max)
{
	int	i;

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
}

void	sort_three_bot_a(t_ps *data, int max)
{
	int	i;

	rra(data);
	rra(data);
	i = data->a->head;
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

void	sort_three_bot_b(t_ps *data, int max)
{
	int	count;

	count = 3;
	while (count-- > 0)
	{
		rrb(data);
		if (data->b->arr[data->b->head] == max)
			pa(data);
	}
	pa(data);
	pa(data);
}
