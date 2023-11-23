/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:00:27 by mho               #+#    #+#             */
/*   Updated: 2023/11/22 19:12:53 by mho              ###   ########.fr       */
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
		stack->tail = i_downdown(stack, stack->tail);
		stack->arr[stack->tail] = stack->arr[stack->head];
		stack->arr[stack->head] = 0;
		stack->head = i_downdown(stack, stack->head);
	}
}

void	ra(t_ps *data)
{
	rotate(data->a);
	ft_lstadd_back(data->op, ft_lstnew("ra"));
}

void	rb(t_ps *data)
{
	rotate(data->b);
	ft_lstadd_back(data->op, ft_lstnew("rb"));
}
