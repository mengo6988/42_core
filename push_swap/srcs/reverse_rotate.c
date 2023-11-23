/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:02:52 by mho               #+#    #+#             */
/*   Updated: 2023/11/22 19:12:57 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	if (is_full(stack))
	{
		stack->head = stack->tail;
		stack->tail = i_upup(stack, stack->tail);
	}
	else
	{
		stack->head = i_upup(stack, stack->head);
		stack->arr[stack->head] = stack->arr[stack->tail];
		stack->arr[stack->tail] = 0;
		stack->tail = i_upup(stack, stack->tail);
	}
}

void	rra(t_ps *data)
{
	reverse_rotate(data->a);
	ft_lstadd_back(data->op, ft_lstnew("rra"));
}

void	rrb(t_ps *data)
{
	reverse_rotate(data->b);
	ft_lstadd_back(data->op, ft_lstnew("rrb"));
}
