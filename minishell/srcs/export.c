#include "minishell.h"

void export_to_env(t_ms *ms, char *s) {
  int i;
  char *key;

  i = 0;
  while (s[i] && s[i] != '=')
    i++;
  if (!s[i])
    return;
  key = ft_strndup(s, i);
  i = find_key(ms->env, key);
  free(key);
  if (i == -1) {
    // printf("not found = %s\n", s);
    insert_new_env(ms, s);
  } else {
    // printf("found = %s\n", s);
    replace_env(ms, s, i);
  }
}

int export(t_ms *ms, char **args) {
  int i;

  if (!args[1]) {
    i = -1;
    while (ms->env[++i])
      ft_printf("declare -x %s\n", ms->env[i]);
  } else {
    i = 0;
    while (args[++i])
      export_to_env(ms, args[i]);
  }
  return (0);
}
