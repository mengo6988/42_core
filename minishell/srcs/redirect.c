#include "mini_structs.h"
#include "minishell.h"

void handle_rdr(t_ms *ms) {
  t_token *current;
  t_token *cmd;
  int flag;

  current = ms->token;
  while (current) {
    if (current->type == CMD)
      cmd = current;
    if (current->type == PIPE) {
      cmd = NULL;
      flag = 0;
    }
    if (current->rdr_type != 0 && current->rdr_type != HEREDOC && cmd)
      add_rdr(current, cmd);
    else if (current->rdr_type == HEREDOC && flag == 0 && cmd) {
      flag = 1;
      add_rdr(current, cmd);
    }
    current = current->next;
  }
}

void add_rdr(t_token *current, t_token *cmd) {
  char *here;

  if (current->rdr_type == OUT || current->rdr_type == APPEND)
    cmd->outfile = insert_2d_arr(cmd->outfile, current->args[1]);
  else if (current->rdr_type == IN)
    cmd->infile = insert_2d_arr(cmd->infile, current->args[1]);
  else {
    here = get_heredoc_file();
    cmd->infile = insert_2d_arr(cmd->infile, here);
    free(here);
  }
}

void delete_rdr(t_ms *ms) {
  t_token *current;
  t_token *temp;
  int flag;

  current = ms->token;
  while (current) {
    if (current->type == CMD)
      flag = 1;
    else if (current->type == PIPE)
      flag = 0;
    if (current->rdr_type != 0 && current->rdr_type != HEREDOC && flag == 1) {
      temp = current;
      current = current->next;
      token_delete(temp);
    } else
      current = current->next;
  }
}

void pre_rdr(t_ms *ms) {
  t_token *current;
  t_token *temp;
  t_token *new;
  int flag;

  current = ms->token;
  temp = current;
  while (current) {
    if (current->type == CMD) {
      ft_printf("found cmd\n");
      flag = 1;
    }
    if (current->type == PIPE && flag) {
      ft_printf("found pipe, set flag to 0 \n");
      temp = current;
      flag = 0;
    } else if ((current->type == PIPE && !flag) || (!current->next && !flag)) {
      ft_printf("found pipe, creating null cmd \n");
      new = token_new();
      new->type = CMD;
      new->raw = ft_calloc(1, sizeof(char));
      new->builtin = NONE;
      token_insert(temp, new);
    }
    current = current->next;
  }
}

// TODO: HANDLE THE RDR
