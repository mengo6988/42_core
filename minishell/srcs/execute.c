#include "minishell.h"

// TODO: get env paths -> run it through builtins first, builtins would be done
// on parent process as some of them will affect the env list -> run on execve,
// if close then it ran well, if all dont run then command not found error
// piping will be done individually i think, so before execve... all the
// heredocs will run first too... and also everything before infile/heredoc will
// not be run at all

// int ft_execve(t_ms *ms, char **args)
