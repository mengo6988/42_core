/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:42:03 by mho               #+#    #+#             */
/*   Updated: 2024/01/10 16:44:36 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_valid_args(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strchr(BASE, map[i]) || map[i] == ' ' || map[i] == '\n'
			|| map[i] == '+' || map[i] == '-' || map[i] == 'X'
			|| map[i] == 'x' || map[i] == ',')
			i++;
		else
			return (0);
	}
	return (1);
}

char	*read_file_fdf(char *filename)
{
	int fd;
	char *res;
	char *line;

	res = ft_calloc(1, sizeof(char));
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit(0);
		// ft_error("File error");
	while ((line = get_next_line(fd)))
	{
		res = joinf(res, line);
		free(line);
	}
	if (!check_valid_args(res))
	 	exit(0);

		// ft_error("invalid map");
	return (res);
}

char	***load_map(char *filename)
{
	char *file_data;
	char **split;
	char ***str_map;
	int	i;
	int rows;

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

t_3d **init_coor(char ***map)
{
	t_3d **res;
	int i;
	int j;

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
	int index;

	res->x = j * 30;
	res->y = i * 30;
	res->z = ft_atoi(str) * 30;
	index = 0;
	while (str[index])
	{
		while (ft_isdigit(str[index]))
			index++;
		// if (str[index] == ',')
		// {
		// 	index = index + 2;
		// 	res->color = ft_atoi_base(str + index, BASE);
		// }
	}
}

void	free_shit(char ***map)
{
	int i;
	int j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			free(map[i][j]);
		free(map[i]);
	}
}

t_3d	**load_coor(char *filename, t_data *data)
{
	char ***map;
	int i;
	int j;
	t_3d **res;
	int k;

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


// int	main(void)
// {
// 	char	*filename;
// 	// char ***map;
// 	t_data data;

// 	filename = "test_maps/basictest.fdf";
// 	// get_map(filename, &map);
// 	// map = load_map(filename);
// 	// coor = init_coor(map);
// 	data.coor_3d = load_coor(filename, &data);
// 	// ft_printf("%p", coor[0]);
// 	// ft_printf("%s\n", map);
// 	int i = 0;
// 	if (data.coor_3d[0] == NULL)
// 		printf("NULL");
// 	while (data.coor_3d[i] != NULL)
// 	{
// 		ft_printf("%i ", data.coor_3d[i]->z);
// 		i++;
// 		if (i % data.width == 0)
// 			ft_printf("\n");
// 	}

// 	return (0);
// }
