#include "minishell.h"

void get_env(char **env, t_ms *ms) {
  t_env *res;
  t_env *new;
  int i;

  i = 0;
  res = ft_malloc(sizeof(t_env));
  res->raw = env[0];
  res->next = NULL;
  res->key = NULL;
  res->value = NULL;
  ms->env = res;
  while (env[++i]) {
    new = ft_malloc(sizeof(t_env));
    new->raw = env[i];
    new->next = NULL;
    new->key = NULL;
    new->value = NULL;
    res->next = new;
    res = new;
  }
  process_env(ms);
}

void process_env(t_ms *ms) {
  int i;
  t_env *env;

  env = ms->env;
  while (env) {
    i = 0;
    while (env->raw[i] && env->raw[i] != '=')
      i++;
    env->key = ft_strndup(env->raw, i);
    // printf("keyyy %s\n", env->key);
    env->value = ft_strdup(env->raw + i + 1);
    // printf("rawwww %s\n", env->raw);
    env = env->next;
  }
}

void print_env(t_ms *ms) {
  t_env *env;

  env = ms->env;
  while (env) {
    ft_printf("----------------\n");
    ft_printf("Raw: %s\n", env->raw);
    ft_printf("Key: %s\n", env->key);
    ft_printf("Value: %s\n", env->value);
    ft_printf("----------------\n");
    env = env->next;
  }
}
