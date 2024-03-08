#include "minishell.h"

// TODO: parse throught the tokens and check for heredocs.
//		open the fds... also expand the dollars in heredocs
//		create new file called heredoc, write everything to heredoc
//		delete heredoc file when done

// void handle_heredocs(t_ms *ms) {
//   t_token *current;
//   int count;
//
//   current = ms->token;
//   while (current) {
//     if (current->type)
//   }
// }

char *get_heredoc_file(void) {
  static int i;
  char *res;
  char *number;

  number = ft_itoa(i);
  res = ft_strdup("heredoc_");
  res = joinf(res, number);
  free(number);
  return (res);
}
