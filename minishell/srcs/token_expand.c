#include "libft.h"
#include "minishell.h"

void expand_dollars(t_ms *ms, t_token **head) {
  t_token *current;
  char *key;
  char *value;
  char *res;
  char *temp;

  current = *head;
  while (current) {
    // printf("running: %s\n", current->raw);
    key = get_dollar_key(current->raw);
    while (key != NULL) {
      value = get_env(ms, key);
      res = replace_dollar(current->raw, key, value);
      temp = current->raw;
      current->raw = res;
      free(temp);
      temp = NULL;
      key = get_dollar_key(current->raw);
    }
    current = current->next;
  }
}

// TODO: Get dollar variable name(char *)
// TODO: search env key (char *)
// TODO: replace_string (char *);

char *get_dollar_key(char *s) {
  char *res;
  int i;
  int j;

  i = 0;
  while (s[i] && s[i] != '$')
    i++;
  if (s[i++] != '$')
    return NULL;
  j = 0;
  while (s[i + j] && s[i + j] != ' ' && s[i + j] != '|' && s[i + j] != '<' &&
         s[i + j] != '>' && s[i + j] != '"' && s[i + j] != '\'')
    j++;
  res = ft_strndup(s + i, j);
  return (res);
}

char *replace_dollar(char *s, char *to_replace, char *replacement) {
  int to_replace_len;
  int replacement_len;
  char *res;
  int i;
  char *ptr;

  to_replace_len = ft_strlen(to_replace);
  replacement_len = ft_strlen(replacement);
  res = ft_malloc(sizeof(char) *
                  (ft_strlen(s) + replacement_len - to_replace_len + 2));
  i = 0;
  while (s[i] && s[i] != '$')
    i++;
  ptr = ft_strncpy(res, s, i);
  ptr = ft_strncpy(res + i, replacement, replacement_len);
  ptr = ft_strncpy(ptr + replacement_len, s + i + to_replace_len + 1,
                   ft_strlen(s + i + to_replace_len));
  free(to_replace);
  free(replacement);
  return res;
}
