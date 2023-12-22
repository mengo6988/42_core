/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:06:20 by mho               #+#    #+#             */
/*   Updated: 2023/12/22 08:36:22 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	temp;
	int	head;
	int	head_next;

	head = stack->head;
	head_next = i_downdown(stack, stack->head);
	if (stack->head == stack->tail)
		return ;
	temp = stack->arr[head];
	stack->arr[head] = stack->arr[head_next];
	stack->arr[head_next] = temp;
}

void	sa(t_ps *data)
{
	enum e_op	content;

	content = e_sa;
	swap(data->a);
	op_lstadd_back(&data->op, op_new(content));
}

void	sb(t_ps *data)
{
	enum e_op	content;

	content = e_sb;
	swap(data->b);
	op_lstadd_back(&data->op, op_new(content));
}

void	ss(t_ps *data)
{
	sa(data);
	sb(data);
}
