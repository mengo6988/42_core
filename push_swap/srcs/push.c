/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:44:50 by mho               #+#    #+#             */
/*   Updated: 2023/12/05 15:27:43 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_stack *dest, t_stack *src)
{
	if (is_full(dest) || src->arr[src->head] == 0)
		return ;
	dest->arr[i_upup(dest, dest->head)] = src->arr[src->head];
	dest->head = i_upup(dest, dest->head);
	src->arr[src->head] = 0;
	// if (src->head == src->tail)
	// 	return ;
	src->head = i_downdown(src, src->head);
	// if (src->arr[src->head] == 0)
	// {
	// 	src->head = src->tail;
	// 	return ;
	// }
}

void	pa(t_ps *data)
{
	enum e_op content;
	// int temp_head;
	// int temp_tail;
	// int temp_data;

	if (stack_size(data->b) == 0)
		return ;
	// temp_head = data->a->head;
	// temp_tail = data->a->tail;
	// temp_data = data->a->arr[temp_head];
	content = e_pa;
	push_stack(data->a, data->b);
	op_lstadd_back(&data->op, op_new(content));
	// if (temp_head == temp_tail && temp_data != 0)
	// {
	// 	data->a->tail = data->a->head;
	// }
}

void	pb(t_ps *data)
{
	enum e_op content;

	if (stack_size(data->a) == 0)
		return ;
	content = e_pb;
	push_stack(data->b, data->a);
	op_lstadd_back(&data->op, op_new(content));
}

