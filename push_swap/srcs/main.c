/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:59:52 by mho               #+#    #+#             */
/*   Updated: 2023/11/16 23:52:21 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack *stack_b;

	if (ac < 2)
		return (0);
	stack_a = input(ac, av);
	if (!stack_a || check_duplicate(stack_a))
	{
		ft_printf("Error\n");
		return (0);
	}
}
