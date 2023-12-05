/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 08:42:49 by mho               #+#    #+#             */
/*   Updated: 2023/12/05 13:36:21 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_elements(t_ps *data, enum e_loc from, enum e_loc to)
{
	if (from == TOP_A)
		move_from_top_a(data, to);
	else if (from == TOP_B)
		move_from_top_b(data, to);
	else if (from == BOT_A)
		move_from_bot_a(data, to);
	else if (from == BOT_B)
		move_from_bot_b(data, to);
	return (1);
}

void move_from_top_a(t_ps *data, enum e_loc to)
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

void move_from_top_b(t_ps *data, enum e_loc to)
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

void move_from_bot_b(t_ps *data, enum e_loc to)
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

void move_from_bot_a(t_ps *data, enum e_loc to)
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
