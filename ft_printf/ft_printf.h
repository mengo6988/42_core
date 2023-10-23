/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 08:51:59 by mho               #+#    #+#             */
/*   Updated: 2023/10/21 21:51:40 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

typedef struct s_flags
{
	int	left;
	int	zero;
	int	dot;
	int	hash;
	int	space;
	int	plus;
	int	width;
}	t_flags;

#endif
