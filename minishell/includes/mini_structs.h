#ifndef MINI_STRUCTS_H
#define MINI_STRUCTS_H

typedef int (*t_bif)(struct s_ms *ms, char **args);

typedef enum e_type {
  CMD,
  ARGS,
  REDIRECTION,
  PIPE,
  S_QUOTE,
  D_QUOTE,
  FILEPATH
} t_type;

typedef enum e_rdr { IN = 1, OUT = 2, APPEND = 3, HEREDOC = 4 } t_rdr;

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

typedef enum e_bool { FALSE, TRUE } t_bool;

typedef struct s_token {
  t_type type;
  t_builtin builtin;
  char *raw;
  int i;
  t_rdr rdr_type;
  t_bool is_quotes;
  //  int *pipe;
  //  char **args;
  //  char *infile;
  //  char *outfile;
  // int out_fd;
  //  int in_fd;
  struct s_token *next;
  struct s_token *prev;
} t_token;

typedef struct s_cmd {
  t_type type;
  t_builtin builtin;
  char *raw;
  char **args;
  char *infile;
  char *outfile;
  int in_fd;
  int out_fd;
  struct s_cmd *next;
  struct t_cmd *prev;
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
  char **env;
  char **function_list;
  t_bif function_ptr;
  t_token *token;
  int latest_err;
  int exit;

} t_ms;

#endif
