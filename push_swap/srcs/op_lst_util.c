/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lst_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 08:38:12 by mho               #+#    #+#             */
/*   Updated: 2023/11/28 14:57:59 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ol	*op_new(enum e_op op)
{
	t_ol	*res;

	res = malloc(sizeof(t_ol));
	if (!res)
		return NULL;
	res->next = NULL;
	res->op = op;
	return (res);
}

t_ol	*op_lstlast(t_ol *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	op_lstadd_back(t_ol **lst, t_ol *new)
{
	t_ol *last;

	if (!new || !lst)
		return ;
	if (*lst)
	{
		last = op_lstlast(*lst);
		last->next = new;
	}
	else
		*lst = new;
}
