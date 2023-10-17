/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:34:10 by mho               #+#    #+#             */
/*   Updated: 2023/10/17 08:40:39 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *b, size_t n)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char *)b;
	while (i < n)
	{
		s[i++] = 0;
	}
}