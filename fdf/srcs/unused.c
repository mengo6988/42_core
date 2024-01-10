/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:51:49 by mho               #+#    #+#             */
/*   Updated: 2024/01/05 15:39:39 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_lines(char *filename)
{
	int	fd;
	int	count;
	char *line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	count = 0;
	while (line = get_next_line(fd))
	{
		free(line);
		count++;
	}
	return (count);
}

int	count_words(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ' && str[i] != '\0')
			i++;
		if (str[i] != ' ' && str[i] != '\0')
			count++;
		while (str[i] != ' ' && str[i] != '\0')
			i++;
	}
	return (count);
}

int	check_valid_args(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_isdigit(map[i]) || map[i] == ' ' || map[i] == '\n'
			|| map[i] == '+' || map[i] == '-' || map[i] == 'X'
			|| map[i] == 'x' || map[i] == ',')
			i++;
		else
			return (0);
	}
	return (1);
}

int	*str_to_arr(char *str, t_map* map)
{
	int	i;
	int	*arr;
	int	count;

	if (!check_valid_args(str))
		ft_error("Invalid Map");
	map->cols = count_words(str);
	arr = (int *)malloc(sizeof(int) * map->cols);
	if (!arr)
		return (NULL);
	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ' && str[i] != '\0')
			i++;
		if (str[i] != ' ' && str[i] != '\0')
			arr[count++] = ft_atoi(str + i);
		while (str[i] != ' ' && str[i] != '\0')
			i++;
	}
	return (arr);
}

void	get_map(char *filename, t_map* map)
{
	int		fd;
	int		count;
	char	*temp;

	count = count_lines(filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error("File Error");
	map->map = (int **)malloc(sizeof(int *) * (count));
	map->rows = count;
	if (map->map == NULL)
		ft_error("Malloc failed");
	count = 0;
	while (1)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			break ;
		map->map[count] = str_to_arr(temp, map);
		count++;
		free(temp);
	}
	close(fd);
}

int	main(void)
{
	char	*filename;
	t_map 	map;

	filename = "test_maps/basictest.fdf";
	get_map(filename, &map);
	for (int i = 0; i < map.rows; i++)
	{
		for (int j = 0; j < map.cols; j++)
			ft_printf("%i ", map.map[i][j]);
		ft_printf("\n");
	}
	ft_printf("rows: %i, cols:%i\n", map.rows, map.cols);
	return (0);
}
