/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:38:19 by mho               #+#    #+#             */
/*   Updated: 2023/11/13 12:23:22 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* FOR SA SB SS */
void	swap(t_stack **stack)
{
	t_stack	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
}

/* FOR PA PB */
void	push(t_stack **dest, t_stack **src)
{
	t_stack	*temp;

	if (!*src)
		return ;
	temp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = temp;
}

/* RA RB RR */
void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = (*stack)->next;
	temp->next = NULL;
	last->next = temp;
}

/* RRA RRB RRR */
void	reverse_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = *stack;
	last = *stack;
	while (last->next->next)
		last = last->next;
	while (temp->next)
		temp = temp->next;
	last->next = NULL;
	temp->next = *stack;
	*stack = temp;
}
