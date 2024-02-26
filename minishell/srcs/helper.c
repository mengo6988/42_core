#include "minishell.h"

void *ft_malloc(size_t size) {
  void *res;

  res = malloc(size);
  if (!res) {
    ft_putstr_fd("Malloc fail\n", 2);
    exit(1);
  }
  return (res);
}

char *ft_strndup(const char *s, int len) {
  char *res;
  int i;

  res = ft_calloc(sizeof(char), len + 1);
  if (!res) {
    ft_putstr_fd("Malloc fail\n", 2);
    exit(1);
  }
  i = -1;
  while (++i < len)
    res[i] = s[i];
  return res;
}

int ft_strcmp(const char *s1, const char *s2) {
  int i;

  i = -1;
  while (s1[++i]) {
    if (s1[i] != s2[i])
      return (s1[1] - s2[i]);
  }
  return (0);
}
