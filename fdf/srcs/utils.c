/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:15:19 by mho               #+#    #+#             */
/*   Updated: 2024/01/10 23:25:28 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_atoi_base(char *str, char *base)
{
	int i;
	int res;
	int	j;
	int base_count;

	i = -1;
	res = 0;
	base_count = ft_strlen(base);
	while (str[++i])
	{
		j = -1;
		res *= base_count;
		while (base[++j])
		{
			if (ft_tolower(str[i]) == base[j])
			{
				res += j;
				break ;
			}
			else if (base[j] == '\0')
				exit(0);
		}

	}
	return (res);
}

void	ft_error(char *err)
{
	perror(err);
	exit(0);
}

// int main(void) {
// 	// char *test = "ff";
// 	char *test2 = "fa021";

// 	ft_printf("%s, \n", test2);
// 	ft_printf("test: %u \n test2: \n", ft_atoi_base(test2, BASE) );
// }
