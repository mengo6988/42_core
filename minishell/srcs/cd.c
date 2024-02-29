#include "minishell.h"

int builtin_cd(t_ms *ms, char **args) {
  char *path;
  if (!args[1] || args[1][0] == '~') {
    path = get_env(ms, "HOME");
    if (!path)
      perror("minishell: cd: HOME not set");
  } else if (args[1][0] == '-' && ft_strlen(args[1]) == 1) {
    path = get_env(ms, "OLDPWD");
    if (!path)
      perror("minishell: cd: OLDPWD not set");
  } else
    path = ft_strdup(args[1]);
  if (chdir(path) == -1) {
    perror(path);
  } else
    replace_pwd(ms);
  return (0);
}

// TODO: builtin_cd
// if cd -: swaps oldpwd and pwd
// if cd no args: goes to HOME
// sets pwd and oldpwd and goes to argument

void replace_pwd(t_ms *ms) {
  char *key;
  char *value;

  value = get_env(ms, "PWD");
  key = ft_strdup("OLDPWD=");

  key = joinf(key, value);
  export(ms, key);
  free(value);
  free(key);
  value = getcwd(NULL, 0);
  key = ft_strdup("PWD=");
  key = joinf(key, value);
  export(ms, key);
  free(key);
  return;
}

// TODO: replace oldpwd with pwd
// getcwd and replace pwd with it
