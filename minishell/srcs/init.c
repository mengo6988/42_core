#include "minishell.h"

void ms_init(t_ms *ms, char **env) {
  ms->token = NULL;
  env_init(env, ms);
  ms->input = NULL;
  ms->previous_input = NULL;
  ms->latest_err = 0;
  ms->exit = FALSE;
  func_list_init(ms);
  // func_ptr_init(ms);
}

void func_list_init(t_ms *ms) {
  char **ls;

  ls = ft_malloc(sizeof(char *) * 8);
  ls[0] = ft_strdup("echo");
  ls[1] = ft_strdup("cd");
  ls[2] = ft_strdup("pwd");
  ls[3] = ft_strdup("export");
  ls[4] = ft_strdup("unset");
  ls[5] = ft_strdup("env");
  ls[6] = ft_strdup("exit");
  ls[7] = NULL;
  ms->function_list = ls;
}

// void func_ptr_init(t_ms *ms) {}
