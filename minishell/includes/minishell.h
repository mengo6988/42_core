#ifndef MINISHELL_H
#define MINISHELL_H

#include "libft.h"
#include "mini_structs.h"
#include <fcntl.h>
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

// echo
int echo(t_ms *ms, char **args);
void echo_print(char **args, int flag);

// cd
int cd(t_ms *ms, char **args);
void replace_pwd(t_ms *ms);
int ft_exit(t_ms *ms, char **args);
int pwd(t_ms *ms, char **args);

// UNSET
int unset(t_ms *ms, char **args);
void delete_env_arr(char **env);
int env(t_ms *ms, char **args);

// HELPER
void *ft_malloc(size_t size);
char *ft_strndup(const char *s, int len);
int ft_strcmp(const char *s1, const char *s2);
char *ft_strncpy(char *dst, char *src, size_t len);
char *add_quotes(char *s);

// HELPER2
int ft_isnum(const char *s);
char *join_path(char *path, char *command);
void free_double_array(char **arr);
char **insert_2d_arr(char **arr, char *val);

// READLINE
void ms_readline(t_ms *ms);

// HISTORY
void ms_addhistory(t_ms *ms);

// TOKENIZE
void tokenize(t_ms *ms);
char **ms_split(char *s);

// TOKEN_UTILS
t_token *token_new(void);
void token_add_back(t_token **head, t_token *to_add);
void token_delete(t_token *head);
void token_deleteall(t_token **head);
void token_insert(t_token *current, t_token *to_add);

// DOLLAR UTILS
void expand_dollars(t_ms *ms, char **s);
char *add_quotes(char *s);
char *get_dollar_key(char *s);
char *get_dollar_word(char *s);
char *replace_dollar(char *s, char *to_replace, char *replacement);

// HEREDOC
void handle_heredocs(t_ms *ms);
void delete_heredocs(t_ms *ms);
void execute_heredoc(char *filename, char *eof);
char *heredoc_name_generator(void);
char *get_heredoc(t_token *token);

void rm_heredoc(t_ms *ms);

// REDIR
void handle_rdr(t_ms *ms);
void add_rdr(t_token *current, t_token *cmd);
void delete_rdr(t_ms *ms);
void pre_rdr(t_ms *ms);
t_token *get_cmd(t_token *current);

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
void set_builtin(t_ms *ms);
void combine_tokens(t_ms *ms);
void add_args_to_cmd(t_token **token);

// init
void ms_init(t_ms *ms, char **env);
void func_list_init(t_ms *ms);
void func_ptr_init(t_ms *ms);
char **get_path(t_ms *ms);

void print_token(t_token *head);
#endif
