/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:24:08 by mho               #+#    #+#             */
/*   Updated: 2023/10/22 13:49:41 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_init_flags(t_flags *flags)
{
	flags->left = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->hash = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->width = 0;
	return (flags);
}

int	ft_printf(const char *s, ...)
{
	t_flags	*flags;
	int		i;
	va_list	args;

	va_start(args, *s);
	flags = (t_flags *)malloc(sizeof(t_flags));
	if (!flags)
		return (-1);
	ft_init_flags(flags);
	i = -1;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			ft_check_flags(s, flags, i);
			ft_check_format(s, flags, i);
		}
		else
			ft_putchar_fd(1, s[i]);
	}
	return (i);
}
