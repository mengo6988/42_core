/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 07:43:34 by mho               #+#    #+#             */
/*   Updated: 2023/10/19 22:00:40 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *hs, const char *nd, size_t len)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!hs)
		return (NULL);
	res = (char *)hs;
	if (*nd == '\0')
		return (res);
	i = 0;
	while (res[i] != '\0' && (i < len))
	{
		j = 0;
		while (res[i + j] == nd[j] && (i + j < len))
		{
			if (nd[j + 1] == '\0')
				return (res + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
