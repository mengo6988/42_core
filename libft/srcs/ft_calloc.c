/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 08:31:46 by mho               #+#    #+#             */
/*   Updated: 2023/10/17 11:01:59 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dest;
	size_t	total_size;

	total_size = count * size;
	dest = malloc(total_size);
	if (!dest)
		return (0);
	dest = ft_memset(dest, 0, total_size);
	return (dest);
}
