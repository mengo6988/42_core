#include "minishell.h"

void ms_readline(t_ms *ms) {
  t_token *current;

  ms->input = readline("minishell > ");
  ms_addhistory(ms);
  tokenize(ms);
  current = ms->token;
  while (current) {
    if (current->type != S_QUOTE)
      expand_dollars(ms, &current->raw);
    current = current->next;
  }
  token_rmquotes(ms);
  token_settype(ms);
  set_builtin(ms);
  combine_tokens(ms);
  pre_rdr(ms);
  handle_rdr(ms);
  delete_rdr(ms);
  print_token(ms->token);
  token_deleteall(&ms->token);
  free(ms->input);
  ms->input = NULL;
}
