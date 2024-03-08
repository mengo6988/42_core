#include "minishell.h"
#include <stdio.h>

t_token *token_new(void) {
  t_token *res;

  res = ft_malloc(sizeof(t_token));
  res->raw = NULL;
  res->next = NULL;
  res->prev = NULL;
  res->args = NULL;
  // res->pipe = NULL;
  res->infile = NULL;
  res->outfile = NULL;
  res->rdr_type = 0;
  res->in_fd = -1;
  res->out_fd = -1;
  res->i = 0;
  return (res);
}

void token_add_back(t_token **head, t_token *to_add) {
  t_token *current;

  current = *head;
  if (!(*head)) {
    to_add->i = 0;
    *head = to_add;
    return;
  }
  while (current->next) {
    current = current->next;
  }
  to_add->i = (current->i) + 1;
  current->next = to_add;
  to_add->prev = current;
}

void token_delete(t_token *token) {
  t_token *current;
  t_token *temp_next;
  t_token *temp_prev;

  current = token;
  temp_next = current->next;
  temp_prev = current->prev;
  if (temp_next)
    temp_next->prev = temp_prev;
  if (temp_prev)
    temp_prev->next = temp_next;
  free(current->raw);
  free(current);
  return;
}

void token_deleteall(t_token **head) {
  t_token *current;
  t_token *tmp;

  current = *head;
  while (current) {
    free(current->raw);
    tmp = current;
    current = current->next;
    free(tmp);
  }
  *head = NULL;
}

void token_insert(t_token *current, t_token *to_add) {
  if (current->next) {
    t_token *temp = current->next;
    to_add->next = current->next;
    to_add->prev = current;

    current->next = to_add;
    temp->prev = to_add;
    // printf("\n");
    // printf("current: %p\n", current);
    // printf("current next prev: %p\n", current->next->prev);
    // printf("current prev: %p\n", current->prev);
    // printf("current next: %p\n", &current->next);
    // printf("to_add: %p\n", to_add);
    // printf("to_add next: %p\n", to_add->next);
    // printf("to_add next prev: %p\n", to_add->next->prev);
    // printf("\n");
  } else {
    current->next = to_add;
    to_add->prev = current;
  }
}
