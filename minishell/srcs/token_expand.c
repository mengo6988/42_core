#include "libft.h"
#include "mini_structs.h"
#include "minishell.h"

void expand_dollars(t_ms *ms, char **s) {
  char *key;
  char *value;
  char *res;
  char *temp;

  key = get_dollar_key(*s);
  while (key != NULL) {
    value = get_env(ms, key);
    res = replace_dollar(*s, key, value);
    temp = *s;
    *s = res;
    free(temp);
    temp = NULL;
    key = get_dollar_key(*s);
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
  while (s[i] && s[i] != '$') {
    i++;
  }
  if (s[i++] != '$')
    return NULL;
  j = 0;
  if (s[i + j] == '?')
    return (ft_strdup("?"));
  while (s[i + j] && s[i + j] != ' ' && s[i + j] != '|' && s[i + j] != '<' &&
         s[i + j] != '>' && s[i + j] != '"' && s[i + j] != '\'' &&
         s[i + j] != '?')
    j++;
  res = ft_strndup(s + i, j);
  // res = get_dollar_word(s + i);
  return (res);
}

char *get_dollar_word(char *s) {
  char *tokens;
  int i;
  char *res;

  i = 0;
  tokens = ft_strdup(" |<>\"'?");
  while (s[i] && !ft_strchr(tokens, s[i]))
    i++;
  res = ft_strndup(s, i);
  free(tokens);
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
                  (ft_strlen(s) + replacement_len - to_replace_len + 1));
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
