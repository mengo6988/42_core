/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:05:57 by mho               #+#    #+#             */
/*   Updated: 2023/12/20 10:07:24 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "../libft/libft.h"
/* access execve fork read write close dup dup2 pipe */
# include <unistd.h>
/* pid_t */
# include <sys/types.h>
// # include <sys/uio.h>

/* malloc free exit */
# include <stdlib.h>

/* open unlink O_RDONLY */
# include <fcntl.h>

/* waitpid wait */
# include <sys/wait.h>

/* strerror */
# include <string.h>

/* perror */
# include <stdio.h>

# define INFILE_ERR "Infile Error"
# define OUTFILE_ERR "Outfile Error"
# define INPUT_ERR "Invalid Number of Arguments"

typedef struct s_pipex
{
	int in_fd;
	int out_fd;
	char **path;
	// char **path;
	char ***cmd_args;
	char *infile;
	char *outfile;
	char *delimiter;
	int cmd_index;
}	t_pipex;


#endif
