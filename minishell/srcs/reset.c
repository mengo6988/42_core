#include "minishell.h"

void rm_heredoc(t_ms *ms) {
  t_token *token;
  int i;

  token = ms->token;
  while (token) {
    i = -1;
    while (token->infile[++i]) {
      if (ft_strncmp(token->infile[i], "heredoc", 7) == 0)
        unlink(token->infile[i]);
    }
    token = token->next;
  }
}
