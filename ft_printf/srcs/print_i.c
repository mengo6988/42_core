/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:14:13 by mho               #+#    #+#             */
/*   Updated: 2023/10/30 16:26:29 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_intlen(int n, int base, t_flags *flags)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		if (flags->plus || flags->space)
			return (2);
		return (1);
	}
	if ((flags->plus && n > 0) || n < 0 || (flags->space && n >= 0))
		len++;
	while (n)
	{
		len++;
		n /= base;
	}
	return (len);
}

void	ft_putnbr_id(int n, int fd)
{
	long	nb;

	nb = (long)n;
	if (nb == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (nb < 0)
		nb = -nb;
	if (nb < 10)
		ft_putchar_fd((nb + '0'), fd);
	else
	{
		ft_putnbr_fd((nb / 10), fd);
		ft_putnbr_fd((nb % 10), fd);
	}
}

int	ft_putnbr(int n, t_flags *flags)
{
	int	len;

	len = ft_intlen(n, 10, flags);
	if (flags->plus && n >= 0)
		ft_putchar_fd('+', 1);
	else if (flags->space && n >= 0 && !flags->plus)
		ft_putchar_fd(' ', 1);
	else if (n < 0)
	{
		flags->precision++;
		ft_putchar_fd('-', 1);
	}
	if (flags->zero && !flags->left)
		len += ft_print_width(flags->width - len, '0');
	if (flags->precision)
		len += ft_print_width(flags->precision - len, '0');
	ft_putnbr_id(n, 1);
	return (len);
}

int	ft_print_i(t_flags *flags, int n)
{
	int	len;
	int	int_len;

	int_len = ft_intlen(n, 10, flags);
	len = 0;
	if (flags->width || flags->precision)
		len += ft_print_ii(flags, n, len, int_len);
	else
		len += ft_putnbr(n, flags);
	return (len);
}

int	ft_print_ii(t_flags *flags, int n, int len, int intlen)
{
	flags->width = flags->width - flags->precision;
	if (flags->left)
	{
		len += ft_putnbr(n, flags);
		len += ft_print_width(flags->width - intlen, ' ');
	}
	else
	{
		if (!flags->zero)
			len += ft_print_width(flags->width - intlen, ' ');
		len += ft_putnbr(n, flags);
	}
	return (len);
}
