#include "minishell.h"

t_token *token_new(char *s) {
  t_token *res;

  res = ft_malloc(sizeof(t_token));
  res->raw = ft_stdup(s);
  res->next = NULL;
  res->prev = NULL;
  res->i = 0;
  return res;
}

void token_add_back(t_token *head, t_token *to_add) {
  t_token *current;

  current = head;
  while (current->next) {
    current = current->next;
  }
  current->next = to_add;
  to_add->prev = current;
}

void token_delete(t_token *head, int i) {
  t_token *current;
  t_token *temp_next;
  t_token *temp_prev

      current = head;
  while (current) {
    if (current->i == i) {
      temp_next = current->next;
      temp->prev = current->prev;
      temp_next->prev = temp_prev;
      temp_prev->next = temp_next;
      free(current->raw);
      free(current);
      return;
    } else {
      current = current->next;
    }
  }
  ft_printf("index out of range...\n");
  return;
}
