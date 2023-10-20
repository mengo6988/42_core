/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 07:18:50 by mho               #+#    #+#             */
/*   Updated: 2023/10/19 21:39:39 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*res;

	if (!s)
		return (NULL);
	res = (char *)s;
	while (*res != '\0')
	{
		if (*res == (unsigned char)c)
			return (res);
		res++;
	}
	if (*res == '\0' && c == '\0')
		return (res);
	return (NULL);
}
