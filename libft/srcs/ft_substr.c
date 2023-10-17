/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:08:43 by mho               #+#    #+#             */
/*   Updated: 2023/10/17 09:49:20 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	st;
	size_t	i;

	sub = (char *)malloc(len + 1);
	if (*s == '\0' || !sub)
		return (0);
	st = start;
	i = 0;
	while ((i + st) < ft_strlen(s) && i < len)
	{
		sub[i] = s[st + i++];
	}
	sub[i] = '\0';
	return (sub);
}
