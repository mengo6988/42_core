#include "minishell.h"

static int	ms_count_words(char *s)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	count = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t')
			flag = 0;
		else if (s[i] != ' ' && s[i] != '\t' && flag == 0)
		{
			flag = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static char	*ft_wordup(char const *s, size_t start, size_t end)
{
	char	*res;
	size_t	i;

	i = 0;
	res = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!res)
		return (0);
	while (start < end)
	{
		res[i] = s[start];
		start++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	**ms_split(char *s)
{
	int		i;
	int		wc;
	int		index;
	int		j;
	char	**res;

	i = 0;
	wc = ms_count_words(s);
	res = ft_malloc((sizeof(char *) * (wc + 1)));
	index = -1;
	while (++index < wc)
	{
		while ((s[i] && s[i] == ' ') || (s[i] && s[i] == '\t'))
			i++;
		j = 0;
		while (s[i + j] && s[i + j] != ' ' && s[i + j] != '\t')
			j++;
		res[index] = ft_wordup(s, i, (i + j));
		i += j;
	}
	res[index] = NULL;
	return (res);
}
