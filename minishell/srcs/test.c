#include "minishell.h"

void print_token(t_token *head) {
  t_token *current;
  int i;

  if (!head) {
    ft_printf("nothing here\n");
    return;
  }
  char *list[11] = {"CMD",     "ARGS",    "REDIRECTION", "PIPE",
                    "S_QUOTE", "D_QUOTE", "FILEPATH"};
  char *rdr[5] = {"NONE", "IN", "OUT", "APP", "HERE"};
  current = head;
  i = 0;
  while (current) {
    ft_printf("---------------TOKEN------------\n");
    ft_printf("%i \n", i);
    ft_printf("raw = %s\n", current->raw);
    ft_printf("type = %s\n", list[current->type]);
    ft_printf("rdr = %s\n", rdr[current->rdr_type]);
    ft_printf("--------------------------------\n");
    i++;
    current = current->next;
  }
}

int main(int ac, char **av, char **env) {
  t_ms ms;
  // char *test;

  (void)ac;
  (void)av;
  env_init(env, &ms);
  // print_env(&ms);
  ms.token = NULL;
  // for (int i = 0; ms.env[i]; i++)
  //   ft_printf("%s\n", ms.env[i]);
  while (1) {
    ms.input = readline("minishell > ");
    ms_addhistory(&ms);
    tokenize(&ms);
    expand_dollars(&ms, &(ms.token));
    token_rmquotes(&ms);
    token_settype(&ms);
    print_token(ms.token);
    token_deleteall(&ms.token);
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
// only takes -n once
// cd with relative/absolute path
// pwd with no options
// export with no option
// unset with no options
// env with no options/arguments
// exit with no options
//
// HACK: echo, pwd, env can use the builtin scripts
//
// NOTE: export dones?
