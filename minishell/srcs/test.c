#include "minishell.h"

int main(int ac, char **av, char **env) {
  t_ms ms;
  // char *test;

  (void)ac;
  (void)av;
  // for (int i = 0; env[i]; i++) {
  //   printf("%s\n", env[i]);
  // }
  get_env(env, &ms);
  // print_env(&ms);
  ms.token = NULL;
  while (1) {
    // test = readline("minishell > ");
    ms.input = readline("minishell > ");
    // ms.input = ft_strdup(test);
    // free(test);
    ms_addhistory(&ms);
    tokenize(&ms);
    token_deleteall(ms.token);
    free(ms.input);
    ms.input = NULL;
  }
  return (0);
}

// TODO: Parsing/tokenizing the input...
// TODO: Handling the pipes, open fd and closing the unnecasarry ones
// 	heredoc is a must as well...
//
// TODO: Checking the access/if function/cmd is available, then execve it
// TODO: Reset the arguments to wait for next input

// FIX: Handling the signals
// exit status has to be right

// WARN: echo with -n option
// cd with relative/absolute path
// pwd with no options
// export with no option
// unset with no options
// env with no options/arguments
// exit with no options
