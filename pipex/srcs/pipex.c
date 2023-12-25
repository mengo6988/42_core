/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:09:17 by mho               #+#    #+#             */
/*   Updated: 2023/12/26 07:39:25 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_here_doc(char *delimiter, int *pipe_fd)
{
	char	*res;

	close(pipe_fd[0]);
	while (1)
	{
		write(STDOUT_FILENO, "here_doc> ", 10);
		res = get_next_line(STDIN_FILENO);
		if (ft_strncmp(res, delimiter, ft_strlen(delimiter)) == 0)
		{
			free(res);
			exit(0);
		}
		ft_putstr_fd(res, pipe_fd[1]);
		free(res);
	}
}

void	here_doc(char *delimiter)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
		exit(0);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (!pid)
		ft_here_doc(delimiter, pipe_fd);
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	execute(t_pipex *pipex, char **av, char **envp)
{
	char	*path;
	int		i;
	char	**cmd_args;

	cmd_args = ft_split(av[pipex->cmd_index], ' ');
	i = -1;
	while (pipex->path[++i])
	{
		path = ft_strjoin(pipex->path[i], cmd_args[0]);
		if (access(path, F_OK) == 0)
			break ;
		free(path);
		path = NULL;
	}
	if (!path)
	{
		i = -1;
		while (cmd_args[++i])
			free(cmd_args[i]);
		free(cmd_args);
		ft_error("Command Not Found", 127);
	}
	release(pipex);
	if (execve(path, cmd_args, envp) == -1)
		ft_error("Error", EXIT_FAILURE);
}

void	child_process(t_pipex *pipex, char **av, char **envp)
{
	pid_t	pid;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		exit(0);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (!pid)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		execute(pipex, av, envp);
	}
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	if (ac > 4)
	{
		pipex_init(&pipex, ac, av, envp);
		if (ft_strncmp(av[1], "here_doc", 8) == 0)
			here_doc(pipex.delimiter);
		else
			dup2(pipex.in_fd, STDIN_FILENO);

		while (pipex.cmd_index < (ac - 2))
		{
			child_process(&pipex, av, envp);
			pipex.cmd_index++;
		}
		dup2(pipex.out_fd, STDOUT_FILENO);
		execute(&pipex, av, envp);
	}
	ft_error("Invalid Args", EXIT_FAILURE);
}
