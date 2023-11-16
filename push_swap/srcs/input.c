/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:53:42 by mho               #+#    #+#             */
/*   Updated: 2023/11/16 23:49:02 by mho              ###   ########.fr       */
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
}

t_stack	*input(int ac, char **av)
{
	int		i;
	t_stack	*new_node;
	t_stack	*stack_a;

	i = 0;
	while (++i < ac)
	{
		if (!str_isvalid(av[i]))
			return (NULL);
		if (i == 1)
			stack_a = stack_new(ft_atoi(av[i]));
		else
		{
			new_node = stack_new(ft_atoi(av[i]));
			stack_add_back(&stack_a, new_node);
		}
	}
	return (stack_a);
}

int	check_duplicate(t_stack *stack_a)
{
	t_stack	*i;
	t_stack	*j;

	i = stack_a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value == j->value)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}
