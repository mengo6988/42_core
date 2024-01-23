/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:42:03 by mho               #+#    #+#             */
/*   Updated: 2024/01/16 16:42:21 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*read_file_fdf(char *filename)
{
	int		fd;
	char	*res;
	char	*line;

	res = ft_calloc(1, sizeof(char));
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error("File error");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		res = joinf(res, line);
		free(line);
	}
	if (!check_valid_args(res))
		ft_error("Invalid Map");
	return (res);
}

char	***load_map(char *filename)
{
	char	*file_data;
	char	**split;
	char	***str_map;
	int		i;
	int		rows;

	file_data = read_file_fdf(filename);
	split = ft_split(file_data, '\n');
	i = -1;
	rows = 0;
	while (split[++i])
		rows++;
	str_map = malloc(sizeof(char **) * (rows + 1));
	str_map[rows] = NULL;
	i = -1;
	while (split[++i])
	{
		str_map[i] = ft_split(split[i], ' ');
		free(split[i]);
	}
	free(file_data);
	free(split);
	return (str_map);
}

t_3d	**init_coor(char ***map)
{
	t_3d	**res;
	int		i;
	int		j;

	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
			j++;
	}
	res = malloc(sizeof(t_3d *) * ((i * j) + 1));
	return (res);
}

void	str_to_coor(char *str, int i, int j, t_3d *res)
{
	int	index;

	res->x = j;
	res->y = i;
	res->z = ft_atoi(str);
	index = 0;
	while (str[index])
	{
		while (ft_isdigit(str[index]) || str[index] == '-')
			index++;
		if (str[index] == ',')
		{
			index = index + 3;
			res->color = ft_atoi_base(str + index, BASE);
			break ;
		}
		else
		{
			if (res->z > 0)
				res->color = 0x00FFFF;
			else
				res->color = 0xFFCC99;
		}
	}
}

t_3d	**load_coor(char *filename, t_data *data)
{
	char	***map;
	int		i;
	int		j;
	t_3d	**res;
	int		k;

	map = load_map(filename);
	res = init_coor(map);
	i = -1;
	k = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			res[k] = malloc(sizeof(t_3d));
			str_to_coor(map[i][j], i, j, res[k]);
			k++;
		}
	}
	free_shit(map);
	data->height = i;
	data->width = j;
	res[k] = NULL;
	return (res);
}
