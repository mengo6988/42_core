#ifndef MINI_STRUCTS_H
#define MINI_STRUCTS_H

typedef enum e_type {
  CMD,
  ARGS,
  RE_IN,
  RE_OUT,
  RE_APP,
  HEREDOC,
  PIPE,
  S_QUOTE,
  D_QUOTE,
  DOLLAR,
  ASSIGNMENT
} t_type;

typedef enum e_builtin {
  ECHO,
  CD,
  PWD,
  EXPORT,
  UNSET,
  ENV,
  EXIT,
  NONE
} t_builtin;

typedef struct s_token {
  t_type type;
  t_builtin builtin;
  char *raw;
  int i;
  struct s_token *next;
  struct s_token *prev;
} t_token;

typedef struct s_cmd {

} t_cmd;

typedef struct s_env {
  char *raw;
  char *key;
  char *value;
  struct s_env *next;
} t_env;

typedef struct s_ms {
  char *input;
  char *previous_input;
  t_env *env;
  t_token *token;
  int exit;

} t_ms;

#endif
