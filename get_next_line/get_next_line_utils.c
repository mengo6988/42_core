/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:05:42 by mho               #+#    #+#             */
/*   Updated: 2023/11/01 17:01:39 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	dest = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!dest)
		return (0);
	i = -1;
	while (s1[++i])
		dest[i] = s1[i];
	j = 0;
	while (s2[j])
		dest[i++] = s2[j++];
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*res;

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

void	*ft_calloc(size_t count, size_t size)
{
	void	*dest;
	size_t	total_size;

	if ((size != 0 && count > UINT_MAX / size)
		|| (count != 0 && size > UINT_MAX / count))
		dest = NULL;
	else
	{
		total_size = count * size;
		dest = malloc(total_size);
		if (!dest)
			return (0);
		dest = ft_memset(dest, 0, total_size);
	}
	return (dest);
}

void	*ft_memset(void *b, int c, size_t len)
{
	char	*s;
	size_t	i;

	s = b;
	i = 0;
	while (i < len)
		s[i++] = c;
	return (s);
}
