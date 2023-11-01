/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:05:39 by mho               #+#    #+#             */
/*   Updated: 2023/11/01 18:15:03 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

/* Utility functions */
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
/*
 * @brief allocates enough space for count with size. and fills with zero
 * @param count Number of objects to allocate.
 * @param size size of the objects to allocate.
 * @return A pointer to the allocated memory.  If count or size is 0,
	then calloc() returns either NULL,
	or a unique pointer value that can later be successfully passed to free().
 */
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);

/* Main Functions */
/*
* @brief joins buffer to the result and free the temp buffer
* @param res result string
* @param buffer buffer string
* @return A pointer to the joined string
*/
char	*joinf(char *res, char *buffer);
/*
* @brief reads the file and appends to result string until '\n'
* @param fd file descriptor
* @param res result string
* @return A pointer to the result string
*/
char	*read_file(int fd, char *res);
/*
* @brief gets the line up to '\n' from buffer
* @param buffer buffer string
* @return A pointer to the line string
*/
char	*get_line(char *buffer);
/*
* @brief trims the buffer to the remaining string after '\n'
* @param buffer buffer string
* @return A pointer to the remaining string
*/
char	*trim_buffer(char *buffer);
/*
* @brief returns a line read from a file descriptor (til '\n')
* @param fd file descriptor
* @return A pointer to the line that has been read, or NULL if an error occurs
*		or if there is nothing else to read.
*/
char	*get_next_line(int fd);

#endif
