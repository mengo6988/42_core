/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 08:51:59 by mho               #+#    #+#             */
/*   Updated: 2023/10/17 16:27:36 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_isascii(char c);
int		ft_isprint(char c);
int		ft_isalpha(char c);
int		ft_isdigit(char c);
int		ft_isalnum(char c);

int		ft_tolower(int c);
int		toupper(int c);

void	ft_bzero(void *b, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strdup(const char *s1);
void	*ft_calloc(size_t count, size_t size);

size_t	ft_strlen(const char *s);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *hs, const char *nd, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

size_t	strlcat(char *dest, const char *src, size_t len);
size_t	strlcpy(char *dst, const char *src, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

int		ft_atoi(const char *s);
char	*ft_itoa(int n);

typedef s_list
{
	void	*content;
	struct	*s_list;
}		t_list;

#endif
