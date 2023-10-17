/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 07:33:46 by mho               #+#    #+#             */
/*   Updated: 2023/10/17 08:40:49 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*t;
	size_t		i;

	t = (const char *)s;
	while (i < n)
	{
		if (t[i] == c)
			return (t + i);
		i++;
	}
	return (NULL);
}
