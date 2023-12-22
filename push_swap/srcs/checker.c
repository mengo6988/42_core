/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 07:52:04 by mho               #+#    #+#             */
/*   Updated: 2023/12/22 10:44:00 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_op(char *op, t_ps *data)
{
	if (!ft_strncmp(op, "ra\n", 4))
		ra(data);
	else if (!ft_strncmp(op, "rb\n", 4))
		rb(data);
	else if (!ft_strncmp(op, "rr\n", 4))
		rr(data);
	else if (!ft_strncmp(op, "rra\n", 5))
		rra(data);
	else if (!ft_strncmp(op, "rrb\n", 5))
		rrb(data);
	else if (!ft_strncmp(op, "rrr\n", 5))
		rrr(data);
	else if (!ft_strncmp(op, "pa\n", 4))
		pa(data);
	else if (!ft_strncmp(op, "pb\n", 4))
		pb(data);
	else if (!ft_strncmp(op, "sa\n", 4))
		sa(data);
	else if (!ft_strncmp(op, "sb\n", 4))
		sb(data);
	else if (!ft_strncmp(op, "ss\n", 4))
		ss(data);
	else
		exit_error();
}

int	main(int ac, char **av)
{
	t_ps	*data;
	char	*op;

	if (ac < 2)
		exit_error();
	data = malloc(sizeof(t_ps));
	init_ps(data);
	fill_stack(data, ac, av);
	op = get_next_line(0);
	while (op)
	{
		execute_op(op, data);
		free(op);
		op = get_next_line(0);
	}
	free(op);
	if (is_sorted(data->a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	op_lstclear(&data->op, free);
	free_shit(data);
	return (0);
}
