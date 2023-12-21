/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:42:36 by mho               #+#    #+#             */
/*   Updated: 2023/12/21 08:26:46 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	combine_ab(t_ol *op, enum e_op o)
{
	t_ol	*next;

	next = op->next;
	op->op = o;
	op->next = next->next;
	free(next);
}

void	delete_two(t_ol *op)
{
	t_ol	*del1;
	t_ol	*del2;

	del1 = op->next;
	del2 = op->next->next;
	op->op = del2->op;
	op->next = del2->next;
	free(del1);
	free(del2);
}

void	three_to_two(t_ol *op, enum e_op o)
{
	t_ol	*next;
	t_ol	*next2;

	next = op->next;
	next2 = op->next->next;
	op->op = o;
	next->next = next2->next;
	free(next2);
}
