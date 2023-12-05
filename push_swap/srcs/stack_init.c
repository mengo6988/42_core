/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:36:59 by mho               #+#    #+#             */
/*   Updated: 2023/12/05 10:15:50 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_ps(t_ps *data, int ac)
{
	data->a = init_stack(ac - 1);
	data->b = init_stack(ac - 1);
	data->op = NULL;
}

t_stack	*init_stack(int size)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		exit(1);
	stack->head = 0;
	stack->tail = 0;
	stack->size = size;
	stack->arr = (int *)ft_calloc(size, sizeof(int));
	return (stack);
}

void	fill_stack(t_stack *stack, int ac, char **av)
{
	int		i;
	int		*numbers;

	numbers = malloc(sizeof(int *) * (ac - 1));
	if (!numbers)
		return ;
	stack->size = ac - 1;
	stack->tail = ac - 2;
	i = 0;
	while (++i < ac)
		numbers[i - 1] = ft_atoi(av[i]);
	// for (i=0; i < ac; i++)
	// 	ft_printf("%i ", numbers[i]);
	check_duplicates(numbers, stack->size);
	rank_numbers(numbers, stack->arr, stack->size);
	free(numbers);
}

void	check_duplicates(int *numbers, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (numbers[i] == numbers[j] && i != j)
			{
				ft_printf("Error\n");
				exit(0);
			}
			j++;
		}
	}
}

void	rank_numbers(int *to_rank, int *dest, int size)
{
	int	i;
	// int	j;
	// int	lower;

	i = -1;
	while (++i < size)
	{
		// j = -1;
		// lower = 1;
		// while (++j < size)
		// {
		// 	if (to_rank[i] > to_rank[j])
		// 		lower++;
		// }
		// dest[i] = lower;
		dest[i] = to_rank[i];
	}
}
// Stack Utils


