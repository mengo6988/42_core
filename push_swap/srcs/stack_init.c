/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:36:59 by mho               #+#    #+#             */
/*   Updated: 2023/11/22 18:40:54 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	t_stack	*a;
	int		*numbers;

	a = init_stack(ac - 1);
	a->size = ac - 1;
	a->tail = ac - 1;
	i = 0;
	while (++i < ac)
		numbers[i - 1] = ft_atoi(av[i]);
	check_duplicates(numbers);
	rank_numbers(numbers, a->arr, a->size);
}

void	check_duplicates(int *numbers)
{
	int	i;
	int	j;

	i = -1;
	while (numbers[++i])
	{
		j = 0;
		while (numbers[j])
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
	int	j;
	int	lower;

	i = -1;
	while (to_rank[++i])
	{
		j = 0;
		lower = 0;
		while (to_rank[j])
		{
			if (to_rank[i] > to_rank[j])
				lower++;
			j++;
		}
		dest[i] = lower;
	}
}
// Stack Utils


