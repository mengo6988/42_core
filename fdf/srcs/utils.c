/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:15:19 by mho               #+#    #+#             */
/*   Updated: 2024/01/16 16:35:00 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	res;
	int	j;
	int	base_count;

	i = -1;
	res = 0;
	base_count = ft_strlen(base);
	while (str[++i])
	{
		j = -1;
		res *= base_count;
		while (base[++j])
		{
			if (ft_toupper(str[i]) == base[j])
			{
				res += j;
				break ;
			}
			else if (base[j] == '\0')
				ft_error("Invalid File");
		}
	}
	return (res);
}

void	ft_error(char *err)
{
	perror(err);
	exit(0);
}

void	free_all(t_data *data)
{
	int	i;

	free(data->mouse);
	free(data->cam);
	mlx_destroy_image(data->mlx, data->img->mlx_img);
	if (data->img)
		free(data->img);
	i = -1;
	while (++i < data->height * data->width)
	{
		free(data->coor_2d[i]);
		free(data->coor_3d[i]);
	}
	free(data->coor_2d[i]);
	free(data->coor_3d[i]);
	free(data->coor_2d);
	free(data->coor_3d);
	mlx_destroy_window(data->mlx, data->mlx_win);
}

void	free_shit(char ***map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			free(map[i][j]);
		free(map[i][j]);
		free(map[i]);
	}
	free(map[i]);
	free(map);
}

int	check_valid_args(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strchr(BASE, ft_toupper(map[i])) || map[i] == ' '
			|| map[i] == '\n' || map[i] == '+' || map[i] == '-'
			|| map[i] == 'X' || map[i] == 'x' || map[i] == ',')
			i++;
		else
			return (0);
	}
	return (1);
}
