#include "libft.h"
#include "mini_structs.h"
#include "minishell.h"

// TODO: parse throught the tokens and check for heredocs.
//		open the fds... also expand the dollars in heredocs
//		create new file called heredoc, write everything to heredoc
//		delete heredoc file when done

void handle_heredocs(t_ms *ms) {
  t_token *current;
  t_token *cmd;
  char *hd;

  current = ms->token;
  cmd = get_cmd(current);
  hd = get_heredoc(cmd);
  while (current) {
    if (current->type == PIPE) {
      cmd = get_cmd(current);
      if (hd)
        free(hd);
      hd = get_heredoc(cmd);
    } else if (current->type == REDIRECTION && current->rdr_type == HEREDOC)
      execute_heredoc(hd, current->args[1]);
    current = current->next;
  }
  delete_heredocs(ms);
}

void delete_heredocs(t_ms *ms) {
  t_token *current;
  t_token *temp;

  current = ms->token;
  while (current->rdr_type == HEREDOC) {
    temp = current;
    current = current->next;
    token_delete(temp);
    ms->token = current;
  }
  while (current) {
    if (current->rdr_type == HEREDOC) {
      temp = current;
      current = current->next;
      token_delete(temp);
    } else {
      current = current->next;
    }
  }
}

void execute_heredoc(char *filename, char *eof) {
  int fd;
  char *res;
  char *end;

  end = ft_strjoin(eof, "\n");
  fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, S_IRWXU | S_IRGRP | S_IROTH);
  while (1) {
    res = readline("> ");
    if (res == NULL || ft_strcmp(res, end) == 0)
      break;
    ft_putstr_fd(res, fd);
    free(res);
    res = NULL;
  }
  close(fd);
}

char *get_heredoc(t_token *token) {
  int i;
  char *res;

  if (token == NULL) {
    return (NULL);
  }
  i = -1;
  res = NULL;
  while (token->infile[++i]) {
    if (ft_strncmp(token->infile[i], "heredoc", 7) == 0)
      res = ft_strdup(token->infile[i]);
  }
  return (res);
}

char *heredoc_name_generator(void) {
  static int i;
  char *res;
  char *number;

  number = ft_itoa(i++);
  res = ft_strdup("heredoc");
  res = joinf(res, number);
  free(number);
  return (res);
}
