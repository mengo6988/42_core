/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 08:51:59 by mho               #+#    #+#             */
/*   Updated: 2023/10/31 12:26:58 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>

typedef struct s_flags
{
	int	left;
	int	zero;
	int	hash;
	int	space;
	int	plus;
	int	width;
	int	precision;
	int	caps;
	int	dot;
}	t_flags;

int		ft_printf(const char *s, ...);
int		ft_check_format(char s, t_flags *flags, va_list *args);
void	ft_check_flags(const char *s, t_flags *flags, int *i);

void	ft_init_flags(t_flags *flags);
int		is_format(char s);
int		is_flags(char s);
void	ft_check_width_precision(const char *s, t_flags *flags, int *i);

int		ft_putchar(char c);
int		ft_print_width(int width, char c);
int		ft_print_char(t_flags *flags, int c);
int		ft_putstr(char *s, t_flags *flags);
int		ft_print_str(t_flags *flags, char *str);

int		ft_intlen(int n, int base, t_flags *flags);
void	ft_putnbr_id(int n, int fd, t_flags *flags);
int		ft_putnbr(int n, t_flags *flags);
int		ft_print_i(t_flags *flags, int n);
void	ft_print_ii(t_flags *flags, int n, int int_len);

int		ft_print_xx(t_flags *flags, unsigned int n, int len, int hex_len);
int		ft_print_x(t_flags *flags, unsigned int n);
void	ft_putnbr_base(unsigned int n, char *base);
int		ft_puthex(unsigned int n, t_flags *flags);
int		ft_hexlen(unsigned int n, int base, t_flags *flags);

int		ft_print_uu(t_flags *flags, unsigned int n, int len, int intlen);
int		ft_print_u(t_flags *flags, unsigned int n);
int		ft_putui(unsigned int n, t_flags *flags);
void	ft_putui_fd(unsigned int nb, int fd, t_flags *flags);
int		ft_uintlen(unsigned int n, int base, t_flags *flags);

int		ft_print_p(t_flags *flags, unsigned long long n);
int		ft_putp(unsigned long long n);
void	ft_putp_base(unsigned long long n, char *base);
int		ft_ulonglen(unsigned long long n);
int		ft_putstr_custom(char *s);

#endif
