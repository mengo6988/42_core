#ifndef MINISHELL_H
#define MINISHELL_H

#include "libft.h"
#include "mini_structs.h"
#include <readline/history.h>
#include <readline/readline.h>

// ENV LL
// void process_env(t_ms *ms);
// void get_env(char **env, t_ms *ms);
// void print_env(t_ms *ms);

// ENV ARR
void env_init(char **env, t_ms *ms);
int find_key(char **env, char *s);
void insert_new_env(t_ms *ms, char *s);
void replace_env(t_ms *ms, char *s, int i);
char *get_env(t_ms *ms, char *s);

// export
void export_to_env(t_ms *ms, char *s);
int export(t_ms *ms, char **args);

// UNSET
int unset(t_ms *ms, char **args);
void delete_env_arr(char **env);

// HELPER
void *ft_malloc(size_t size);
char *ft_strndup(const char *s, int len);
int ft_strcmp(const char *s1, const char *s2);
char *ft_strncpy(char *dst, char *src, size_t len);

// HISTORY
void ms_addhistory(t_ms *ms);

// TOKENIZE
void tokenize(t_ms *ms);
char **ms_split(char *s);

// TOKEN_UTILS
t_token *token_new(void);
void token_add_back(t_token **head, t_token *to_add);
void token_delete(t_token *head, int i);
void token_deleteall(t_token **head);

// DOLLAR UTILS
void expand_dollars(t_ms *ms, t_token **head);
char *get_dollar_key(char *s);
char *replace_dollar(char *s, char *to_replace, char *replacement);

// CD

int builtin_cd(t_ms *ms, char **args);
void replace_pwd(t_ms *ms);

// TEST

void tk_redir_in(t_ms *ms, int *i);
void tk_redir_out(t_ms *ms, int *i);
void tk_pipe(t_ms *ms, int *i);
void tk_quotes(t_ms *ms, int *i);
void tk_word(t_ms *ms, int *i);

// token_class
void token_rmquotes(t_ms *ms);
void token_settype(t_ms *ms);

void print_token(t_token *head);
#endif
