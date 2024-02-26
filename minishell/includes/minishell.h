#ifndef MINISHELL_H
#define MINISHELL_H

#include "libft.h"
#include "mini_structs.h"
#include <readline/history.h>
#include <readline/readline.h>

// ENV
void process_env(t_ms *ms);
void get_env(char **env, t_ms *ms);
void print_env(t_ms *ms);

// HELPER
void *ft_malloc(size_t size);
char *ft_strndup(const char *s, int len);
int ft_strcmp(const char *s1, const char *s2);

// HISTORY
void ms_addhistory(t_ms *ms);

// TOKENIZE
void tokenize(t_ms *ms);
char **ms_split(char *s);

// TOKEN_UTILS
t_token *token_new(char *s);
void token_add_back(t_token *head, t_token *to_add);

#endif
