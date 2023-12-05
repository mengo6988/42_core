/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:40:29 by mho               #+#    #+#             */
/*   Updated: 2023/12/05 15:31:51 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_full(t_stack *stack)
{
	if (stack->size == stack_size(stack))
		return (1);
	return (0);
}

int	i_downdown(t_stack *stack, int index)
{
	// if (stack_size(stack) == 0)
	// 	return (index);
	if (index == stack->size - 1)
		return (0);
	else
		return (index + 1);
}

int	i_upup(t_stack *stack, int index)
{
	// if (stack_size(stack) == 0)
	// 	return (index);
	if (index == 0)
		return (stack->size - 1);
	else
		return (index - 1);
}

int stack_size(t_stack *stack)
{
	if (stack->head == stack->tail && stack->arr[stack->head] == 0)
		return (0);
	if (stack->arr[stack->head] == 0)
		return (0);
	if (stack->tail < stack->head)
		return ((stack->size - stack->head) + stack->tail + 1);
	else
		return (stack->tail - stack->head + 1);
}
