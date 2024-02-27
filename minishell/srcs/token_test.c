#include "mini_structs.h"
#include "minishell.h"

void tokenize(t_ms *ms) {
  int i;

  i = 0;
  while (ms->input[i]) {
    if (ms->input[i] == ' ')
      i++;
    else if (ms->input[i] == '>')
      tk_redir_out(ms, &i);
    else if (ms->input[i] == '<')
      tk_redir_in(ms, &i);
    else if (ms->input[i] == '|')
      tk_pipe(ms, &i);
    else if (ms->input[i] == '"' || ms->input[i] == '\'')
      tk_quotes(ms, &i);
    else
      tk_word(ms, &i);
  }
}

void tk_redir_in(t_ms *ms, int *i) {
  t_token *new;

  new = token_new();
  if (ms->input[*i + 1] == '<') {
    new->type = HEREDOC;
    new->raw = ft_strndup(ms->input + *i, 2);
    *i += 2;
  } else {
    new->type = RE_IN;
    new->raw = ft_strndup(ms->input + *i, 1);
    (*i)++;
  }
  token_add_back(ms->token, new);
}

void tk_redir_out(t_ms *ms, int *i) {
  t_token *new;

  new = token_new();
  if (ms->input[*i + 1] == '>') {
    new->type = RE_APP;
    new->raw = ft_strndup(ms->input + *i, 2);
    (*i) += 2;
  } else {
    new->type = RE_OUT;
    new->raw = ft_strndup(ms->input + *i, 1);
    (*i)++;
  }
  token_add_back(ms->token, new);
}

void tk_pipe(t_ms *ms, int *i) {
  t_token *new;

  new = token_new();
  new->type = PIPE;
  new->raw = ft_strndup(ms->input + *i, 1);
  token_add_back(ms->token, new);
  (*i)++;
}

void tk_quotes(t_ms *ms, int *i) {
  t_token *new;
  char c;
  int j;

  c = ms->input[*i];
  new = token_new();
  j = 0;
  while (ms->input[*i + j] && ms->input[*i + j] != c)
    j++;
  new->raw = ft_strndup(ms->input + *i, j);
  if (c == '\'')
    new->type = S_QUOTE;
  else
    new->type = D_QUOTE;
  token_add_back(ms->token, new);
  (*i) += j;
}

void tk_word(t_ms *ms, int *i) {
  int j;
  t_token *new;

  new = token_new();
  j = 0;
  while (ms->input[*i + j] && ms->input[*i + j] != ' ' &&
         ms->input[*i + j] != '>' && ms->input[*i + j] != '<' &&
         ms->input[*i + j] != '|' && ms->input[*i + j] != '"' &&
         ms->input[*i + j] != '\'')
    j++;
  new->raw = ft_strndup(ms->input + *i, j);
  token_add_back(ms->token, new);
  (*i) += j;
}
