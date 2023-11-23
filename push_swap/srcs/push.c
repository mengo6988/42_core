/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:44:50 by mho               #+#    #+#             */
/*   Updated: 2023/11/22 19:11:52 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_stack *dest, t_stack *src)
{
	if (is_full(dest))
		return ;
	dest->arr[i_upup(dest, dest->head)] = src->arr[src->head];
	src->arr[src->head] = 0;
	src->head = i_downdown(src, src->head);
	dest->head = i_upup(dest, dest->head);
}

void	pa(t_ps *data)
{
	t_list	*new_node;

	push_stack(data->a, data->b);
	ft_lstadd_back(data->op, ft_lstnew("pa"));
}

void	pb(t_ps *data)
{
	push_stack(data->b, data->a);
	ft_lstadd_back(data->op, ft_lstnew("pb"));
}

