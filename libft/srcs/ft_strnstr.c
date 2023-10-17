/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 07:43:34 by mho               #+#    #+#             */
/*   Updated: 2023/10/17 09:13:14 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hs, const char *nd, size_t len)
{
	size_t	i;
	size_t	j;

	if (*nd == '\0')
		return (hs);
	i = 0;
	while (hs[i])
	{
		j = 0;
		while (hs[i + j] == nd[j] && (i < len))
		{
			if (hs[i + j] == '\0' && nd[i + j] == '\0')
				return (hs + (i + j));
			j++;
		}
		i++;
	}
	return (NULL);
}
