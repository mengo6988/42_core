#include "minishell.h"

int echo(t_ms *ms, char **args) {
  int flag;
  int i;

  if (!args[1][0] && !args[2]) {
    ft_printf("\n");
    return (0);
  }
  flag = 1;
  while (ft_strcmp(args[flag], "-n") == 0)
    flag++;
  echo_print(args, flag);
  return (0);
}

void echo_print(char **args, int flag) {
  int i;

  i = flag;
  while (args[i]) {
    ft_printf("%s", args[i]);
    if (args[i + 1][0] == "'")
      ft_strtrim(args[i + 1], "'");
    else if (args[i + 1][0] == "\"")
      ft_strtrim(args[i + 1], "\"");
    else
      ft_printf(" ");
    i++;
  }
  if (flag <= 1)
    ft_printf("\n");
  return;
}
