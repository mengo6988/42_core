/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 07:48:14 by mho               #+#    #+#             */
/*   Updated: 2023/12/22 07:49:52 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	i;
	int	j;
	int	count;

	i = stack->head;
	j = i_downdown(stack, stack->head);
	count = -1;
	while (++count < stack->size - 1)
	{
		if (stack->arr[i] > stack->arr[j])
			return (0);
		i = i_downdown(stack, i);
		j = i_downdown(stack, i);
	}
	if (stack_size(stack) == stack->size)
		return (1);
	return (0);
}

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_atoi_ps(const char *s)
{
	int		is_pos;
	long	ret;
	int		res;

	is_pos = 1;
	while ((*s >= 9 && *s <= 13) || *s == ' ')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			is_pos *= -1;
		s++;
	}
	ret = 0;
	while (*s && (*s >= '0' && *s <= '9'))
	{
		ret *= 10;
		ret += (*s - '0') * is_pos;
		s++;
	}
	if (ret > INT_MAX || ret < INT_MIN || *s != '\0')
		exit_error();
	res = (int)ret;
	return (res);
}

void	free_shit(t_ps *data)
{
	free(data->a->arr);
	free(data->b->arr);
	free(data->a);
	free(data->b);
	free(data);
}
