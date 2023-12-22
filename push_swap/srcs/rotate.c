/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:00:27 by mho               #+#    #+#             */
/*   Updated: 2023/12/22 09:18:24 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	if (is_full(stack))
	{
		stack->tail = stack->head;
		stack->head = i_downdown(stack, stack->head);
	}
	else
	{
		if (stack->arr[stack->tail] != 0)
			stack->tail = i_downdown(stack, stack->tail);
		stack->arr[stack->tail] = stack->arr[stack->head];
		stack->arr[stack->head] = 0;
		stack->head = i_downdown(stack, stack->head);
	}
}

void	ra(t_ps *data)
{
	enum e_op	content;

	content = e_ra;
	if (stack_size(data->a) == 1)
		return ;
	rotate(data->a);
	op_lstadd_back(&data->op, op_new(content));
}

void	rb(t_ps *data)
{
	enum e_op	content;

	content = e_rb;
	if (stack_size(data->b) == 1)
		return ;
	rotate(data->b);
	op_lstadd_back(&data->op, op_new(content));
}

void	rr(t_ps *data)
{
	ra(data);
	rb(data);
}
