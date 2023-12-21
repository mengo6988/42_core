/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_io.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:53:42 by mho               #+#    #+#             */
/*   Updated: 2023/12/21 08:36:59 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	str_isvalid(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '-' && ft_isdigit(str[i + 1]))
			i++;
		else if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

void	print_op(t_ol *op)
{
	t_ol	*cur;
	char	*arr[11];

	init_ol(arr);
	output_check(op);
	cur = op;
	while (op)
	{
		ft_printf("%s\n", arr[cur->op]);
		op = op->next;
		free(cur);
		cur = op;
	}
}

void	init_ol(char **arr)
{
	arr[0] = "rb";
	arr[1] = "ra";
	arr[2] = "rr";
	arr[3] = "rra";
	arr[4] = "rrb";
	arr[5] = "rrr";
	arr[6] = "pa";
	arr[7] = "pb";
	arr[8] = "sa";
	arr[9] = "sb";
	arr[10] = "ss";
}

void	output_check(t_ol *op)
{
	if ((op->op == e_sa && op->next->op == e_sb) || (op->op == e_sb
			&& op->next->op == e_sa))
		combine_ab(op, e_ss);
	else if ((op->op == e_ra && op->next->op == e_rb) || (op->op == e_rb
			&& op->next->op == e_ra))
		combine_ab(op, e_rr);
	else if ((op->op == e_rra && op->next->op == e_rrb) || (op->op == e_rrb
			&& op->next->op == e_rra))
		combine_ab(op, e_rrr);
	else if ((op->op == e_pa && op->next->op == e_pb) || (op->op == e_pb
			&& op->next->op == e_pa) || (op->op == e_sa && op->next->op == e_sa)
		|| (op->op == e_sb && op->next->op == e_sb))
		delete_two(op);
	else if (op->op == e_ra && op->next->op == e_pb
		&& op->next->next->op == e_rra)
		three_to_two(op, e_sa);
	else if (op->op == e_rb && op->next->op == e_pa
		&& op->next->next->op == e_rrb)
		three_to_two(op, e_sb);
}

char	**parse_args(int ac, char **av)
{
	int		i;
	char	*args;
	char	**res;

	i = 0;
	args = ft_calloc(1, sizeof(char));
	while (++i < ac)
	{
		args = joinf(args, " ");
		args = joinf(args, av[i]);
	}
	res = ft_split(args, ' ');
	free(args);
	return (res);
}
