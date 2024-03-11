#include "minishell.h"

void print_token(t_token *head) {
  t_token *current;

  if (!head) {
    ft_printf("nothing here\n");
    return;
  }
  char *list[11] = {"CMD",     "ARGS",    "REDIRECTION", "PIPE",
                    "S_QUOTE", "D_QUOTE", "FILEPATH"};
  char *rdr[5] = {"NONE", "IN", "OUT", "APP", "HERE"};
  current = head;
  while (current) {
    ft_printf("---------------TOKEN------------\n");
    ft_printf("%i \n", current->i);
    ft_printf("raw = %s\n", current->raw);
    ft_printf("type = %s\n", list[current->type]);
    ft_printf("rdr = %s\n", rdr[current->rdr_type]);
    ft_printf("args = ");
    if (current->args) {
      for (int i = 0; current->args[i]; i++)
        ft_printf("%s, ", current->args[i]);

    } else
      ft_printf("null");
    ft_printf("\n");

    ft_printf("infile = ");
    if (current->infile) {
      for (int i = 0; current->infile[i]; i++)
        ft_printf("%s, ", current->infile[i]);

    } else
      ft_printf("null");
    ft_printf("\n");

    ft_printf("outfile = ");
    if (current->outfile) {
      for (int i = 0; current->outfile[i]; i++)
        ft_printf("%s, ", current->outfile[i]);

    } else
      ft_printf("null");
    ft_printf("\n");
    ft_printf("--------------------------------\n");
    current = current->next;
  }
  // current = head;
  // while (current->next)
  //   current = current->next;
  // printf("\n\n-----------------BACKWARDS-------------\n");
  // while (current) {
  //   ft_printf("---------------TOKENb------------\n");
  //   ft_printf("%i \n", current->i);
  //   ft_printf("raw = %s\n", current->raw);
  //   ft_printf("type = %s\n", list[current->type]);
  //   ft_printf("rdr = %s\n", rdr[current->rdr_type]);
  //   ft_printf("args = ");
  //   if (current->args) {
  //     for (int i = 0; current->args[i]; i++)
  //       ft_printf("%s, ", current->args[i]);
  //
  //   } else
  //     ft_printf("null");
  //   ft_printf("\n");
  //
  //   ft_printf("infile = ");
  //   if (current->infile) {
  //     for (int i = 0; current->infile[i]; i++)
  //       ft_printf("%s, ", current->infile[i]);
  //
  //   } else
  //     ft_printf("null");
  //   ft_printf("\n");
  //
  //   ft_printf("outfile = ");
  //   if (current->outfile) {
  //     for (int i = 0; current->outfile[i]; i++)
  //       ft_printf("%s, ", current->outfile[i]);
  //
  //   } else
  //     ft_printf("null");
  //   ft_printf("\n");
  //   ft_printf("--------------------------------\n");
  //   current = current->prev;
  // }
}

int main(int ac, char **av, char **env) {
  t_ms ms;
  // char *test;

  (void)ac;
  (void)av;
  env_init(env, &ms);
  ms_init(&ms, env);
  // print_env(&ms);
  ms.token = NULL;
  // for (int i = 0; ms.env[i]; i++)
  //   ft_printf("%s\n", ms.env[i]);
  while (1) {
    ms_readline(&ms);
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
