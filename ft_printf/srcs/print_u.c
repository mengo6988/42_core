/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 21:05:05 by mho               #+#    #+#             */
/*   Updated: 2023/10/30 12:19:44 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_uintlen(unsigned int n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n /= base;
	}
	return (len);
}

int	ft_putui(unsigned int n)
{
	int	len;

	len = 0;
	ft_putui_fd(n, 1);
	len = ft_uintlen(n, 10);
	return (len);
}

void	ft_putui_fd(unsigned int nb, int fd)
{
	if (nb == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (nb < 10)
		ft_putchar_fd((nb + '0'), fd);
	else
	{
		ft_putnbr_fd((nb / 10), fd);
		ft_putnbr_fd((nb % 10), fd);
	}
}

int	ft_print_u(t_flags *flags, unsigned int n)
{
	int				len;
	int				int_len;

	int_len = ft_uintlen(n, 10);
	len = 0;
	if (flags->width || flags->precision)
		len += ft_print_uu(flags, n, len, int_len);
	else
		len += ft_putui(n);
	return (len);
}

int	ft_print_uu(t_flags *flags, unsigned int n, int len, int intlen)
{
	flags->width = flags->width - flags->precision;
	if (flags->left)
	{
		len += ft_print_width(flags->precision - intlen, '0');
		len += ft_putui(n);
		len += ft_print_width(flags->width - intlen, ' ');
	}
	else
	{
		if (flags->zero)
			len += ft_print_width(flags->width - intlen, '0');
		else
			len += ft_print_width(flags->width - intlen, ' ');
		len += ft_print_width(flags->precision - intlen, '0');
		len += ft_putui(n);
	}
	return (len);
}
