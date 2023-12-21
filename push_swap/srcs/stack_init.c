/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:36:59 by mho               #+#    #+#             */
/*   Updated: 2023/12/21 09:05:29 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_ps(t_ps *data)
{
	data->a = NULL;
	data->b = NULL;
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

void	fill_stack(t_ps *data, int ac, char **av)
{
	int		i;
	int		*numbers;
	char	**args;
	int		length;

	args = parse_args(ac, av);
	length = 0;
	while (args[length])
		length++;
	data->a = init_stack(length);
	data->b = init_stack(length);
	numbers = malloc(sizeof(int *) * (ac - 1));
	if (!numbers)
		return ;
	data->a->size = length;
	data->a->tail = length - 1;
	i = -1;
	while (args[++i])
		numbers[i] = ft_atoi(args[i]);
	check_duplicates(numbers, data->a->size);
	rank_numbers(numbers, data->a->arr, data->a->size);
	free(numbers);
	free(args);
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
	int	j;
	int	lower;

	i = -1;
	while (++i < size)
	{
		j = -1;
		lower = 1;
		while (++j < size)
		{
			if (to_rank[i] > to_rank[j])
				lower++;
		}
		dest[i] = lower;
	}
}
