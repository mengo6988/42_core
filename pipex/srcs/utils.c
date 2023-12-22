/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:42:16 by mho               #+#    #+#             */
/*   Updated: 2023/12/22 11:44:36 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *err, int exitcode)
{
	perror(err);
	exit(exitcode);
}

char	**format_paths(char **paths, char *joiner)
{
	int		i;
	char	**res;

	i = 0;
	while (paths[i])
		i++;
	res = (char **)malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (paths[++i])
	{
		res[i] = ft_strjoin(paths[i], joiner);
		free(paths[i]);
	}
	res[i] = NULL;
	free(paths);
	return (res);
}

void	release(t_pipex *pipex)
{
	int	i;

	i = -1;
	while (pipex->path[++i])
		free(pipex->path[i]);
	free(pipex->path);
}

char	**get_paths(char **envp, char *string_compare)
{
	int		i;
	int		j;
	char	**paths;
	char	**res;

	i = -1;
	paths = NULL;
	while (envp[++i])
	{
		j = -1;
		while (envp[i][j] != '=')
			j++;
		if (ft_strncmp(envp[i], string_compare, j) == 0)
		{
			paths = ft_split(envp[i] + 5, ':');
			break ;
		}
	}
	res = format_paths(paths, "/");
	return (res);
}

void	pipex_init(t_pipex *pipex, int ac, char **av, char **envp)
{
	pipex->in_fd = 0;
	pipex->out_fd = 0;
	pipex->outfile = av[ac - 1];
	pipex->path = get_paths(envp, "PATH");
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		pipex->cmd_index = 3;
		pipex->delimiter = av[2];
		pipex->infile = NULL;
		pipex->out_fd = open(pipex->outfile, O_WRONLY | O_CREAT | O_APPEND,
				0644);
	}
	else
	{
		pipex->cmd_index = 2;
		pipex->delimiter = NULL;
		pipex->infile = av[1];
		pipex->in_fd = open(pipex->infile, O_RDONLY);
		pipex->out_fd = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC,
				0644);
	}
	if (pipex->out_fd < 0)
		ft_error("File Error", EXIT_FAILURE);
}
