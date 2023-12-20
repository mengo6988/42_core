/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:04:08 by mho               #+#    #+#             */
/*   Updated: 2023/12/19 11:30:59 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main (int ac, char **av)
{

	if (ac < 0)
		return (0);
	if (ft_strncmp(av[1],"here_doc", ft_strlen(av[1])))
	{
	}
	char *res;

	int file = open("here_doc.txt", O_CREAT | O_WRONLY | O_TRUNC, 420);
	int stdin = open(STDIN_FILENO, O_RDONLY);
	if (file < 0)
		return (-1);
	while (1)
	{
		write(STDOUT_FILENO, "heredoc> ", 9);
		res = get_next_line(STDIN_FILENO);
		if (ft_strncmp(res, av[2], ft_strlen(av[2])) == 0)
		{
			free(res);
			exit(0);
		}
		ft_putstr_fd(res, file);
		free(res);
	}
	close(stdin);
}
