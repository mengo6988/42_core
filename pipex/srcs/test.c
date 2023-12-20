/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:09:17 by mho               #+#    #+#             */
/*   Updated: 2023/12/20 15:14:33 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *err, int exitcode)
{
	perror(err);
	exit(exitcode);
}

void	ft_here_doc(char *delimiter, int *pipe_fd)
{
	char *res;

	while (1)
	{
		write(STDOUT_FILENO, "here_doc> ", 10);
		res = get_next_line(STDIN_FILENO);
		if (ft_strncmp(res, delimiter, ft_strlen(delimiter)) == 0)
		{
			free(res);
			exit(0);
		}
		ft_putstr_fd(res, pipe_fd[0]);
		free(res);
	}
}

void here_doc(char *delimiter)
{
	int pipe_fd[2];
	pid_t pid;

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

char **format_paths(char **paths, char *joiner)
{
	int i;
	char **res;

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

char **get_paths(char **envp, char *string_compare)
{
	int i;
	int j;
	char **paths;
	char **res;

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
			break;
		}
	}
	res = format_paths(paths, "/");
	return (res);
}

void	pipex_init(t_pipex *pipex, int ac, char **av, char **envp)
{
	pipex->in_fd = 0;
	pipex->out_fd = 0;
	pipex->outfile = av[ac-1];
	pipex->path = get_paths(envp, "PATH");
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		pipex->cmd_index = 3;
		pipex->delimiter = av[2];
		pipex->infile = NULL;
		pipex->out_fd = open(pipex->outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	else
	{
		pipex->cmd_index = 2;
		pipex->delimiter = NULL;
		pipex->infile = av[1];
		pipex->in_fd = open(pipex->infile, O_RDONLY);
		pipex->out_fd = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	if (pipex->out_fd < 0)
		ft_error("File Error", EXIT_FAILURE);
}

void release(t_pipex *pipex)
{
	int i;

	i = -1;
	while (pipex->path[++i])
		free(pipex->path[i]);
	free(pipex->path);
}

void execute(t_pipex *pipex, char **av, char **envp)
{
	char *path;
	int i;
	char **cmd_args;

	cmd_args = ft_split(av[pipex->cmd_index], ' ');
	i = -1;
	while (pipex->path[++i])
	{
		path = ft_strjoin(pipex->path[i],cmd_args[0]);
		if (access(path, F_OK) == 0)
			break;
		free(path);
		path = NULL;
	}
	if (!path)
	{
		i = -1;
		while(cmd_args[++i])
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
	pid_t pid;
	int pipe_fd[2];

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

int main(int ac, char **av, char **envp)
{
	t_pipex pipex;

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


