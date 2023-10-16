/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:10:27 by mho               #+#    #+#             */
/*   Updated: 2023/10/16 16:19:24 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*srce;
	size_t		i;

	dest = dst;
	srce = src;
	if (srce = dest)
		return (dest);
	else if (dest < srce || dest >= srce + len)
	{
		while (i < len)
			dest[i] = srce[i++];
	}
	else
	{
		while (--len >= 0)
			dest[i] = srce[i];
	}
	return (dest);
}
