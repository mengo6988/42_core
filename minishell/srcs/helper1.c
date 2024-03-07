#include "libft.h"
#include "minishell.h"

int ft_isnum(const char *s) {
  int i;
  char *first;
  char *rest;

  i = 0;
  first = ft_strdup("0123456789+-");
  rest = ft_strdup("0123456789");
  if (!ft_strchr(first, s[0]))
    return (0);
  while (s[++i]) {
    if (!ft_strchr(rest, s[i]))
      return (0);
  }
  return (1);
}

char *join_path(char *path, char *command) {
  char *slash;
  char *temp;
  char *res;

  slash = ft_strdup("/");
  temp = ft_strjoin(path, slash);
  free(slash);
  res = ft_strjoin(temp, command);
  free(temp);
  return (res);
}

void free_double_array(char **arr) {
  int i;

  i = -1;
  while (arr[++i])
    free(arr[i]);
  free(arr);
}