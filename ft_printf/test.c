/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:09:11 by mho               #+#    #+#             */
/*   Updated: 2023/10/30 18:25:21 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	// char *s2 = "Mussum Ipsum, cacilds vidis litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus.";
	// printf("test 2\n");
	int test_len = ft_printf("| 1%-1s, 2%-2s, |", "", "-");
	printf("\n");
	int true_len = printf("| 1%-1s, 2%-2s, |", "", "-");
	printf("\n");
	printf("my len: %i\n", test_len);
	printf("true len: %i\n", true_len);
	printf("\n");
	// printf("test 13\n");
	// ft_printf(" %u ", -9);
	// printf("\n");
	// printf("test 23\n");
	// ft_printf(" %u ", INT_MIN);
	// printf("\n");
	// printf("test 24\n");
	// ft_printf(" %u ", LONG_MAX);
	// printf("\n");
	// printf("test 26\n");
	// ft_printf(" %u ", UINT_MAX);
	// printf("\n");
	// printf("test 28\n");
	// ft_printf(" %u ", 9223372036854775807LL);
	// printf("\n");
	// printf("test 29\n");
	// ft_printf(" %u %u %u %u %u %u %u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// printf("\n");

	return (0);
}
