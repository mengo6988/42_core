/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:36:59 by mho               #+#    #+#             */
/*   Updated: 2023/12/21 15:43:37 by mho              ###   ########.fr       */
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
	if (length == 0)
		exit_error();
	data->a = init_stack(length);
	data->b = init_stack(length);
	numbers = malloc(sizeof(int *) * (length - 1));
	if (!numbers)
		return ;
	data->a->size = length;
	data->a->tail = length - 1;
	i = -1;
	while (args[++i])
		numbers[i] = ft_atoi_ps(args[i]);
	check_duplicates_min_max(numbers, data->a->size);
	rank_numbers(numbers, data->a->arr, data->a->size);
	free(numbers);
	free_args(args);
}

void	check_duplicates_min_max(int *numbers, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		if (numbers[i] > INT_MAX || numbers[i] < INT_MIN)
			exit_error();
		j = -1;
		while (++j < size)
		{
			if (numbers[i] == numbers[j] && i != j)
				exit_error();
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
