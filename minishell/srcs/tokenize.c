#include "minishell.h"

void tokenize(t_ms *ms) {
  char **input;
  int i;
  t_token *new;

  input = ft_split(ms->input, ' ');
  i = -1;
  while (input[++i]) {
    new = token_new(input[i]);
    token_add_back(ms->token, new);
  }
}
