/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:06:20 by mho               #+#    #+#             */
/*   Updated: 2023/11/22 19:13:03 by mho              ###   ########.fr       */
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
	swap(data->a);
	ft_lstadd_back(data->op, ft_lstnew("sa"));
}

void	sb(t_ps *data)
{
	swap(data->b);
	ft_lstadd_back(data->op, ft_lstnew("sb"));
}
