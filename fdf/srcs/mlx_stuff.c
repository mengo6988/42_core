/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:44:04 by mho               #+#    #+#             */
/*   Updated: 2024/01/16 16:35:31 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if ((x >= 0 && x < WINDOW_WIDTH) && (y <= WINDOW_HEIGHT && y >= 0))
	{
		pixel = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
		*(unsigned int *)pixel = color;
	}
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			my_mlx_pix_put(img, j++, i, color);
		i++;
	}
}

void	print_menu(t_data *data)
{
	int	y;

	y = 0;
	mlx_string_put(data->mlx, data->mlx_win, 15, y += 20, 0xFFFFFF, "Tutorial");
	mlx_string_put(data->mlx, data->mlx_win, 15, y += 20, 0xFFFFFF,
		"Zoom: Scroll");
	mlx_string_put(data->mlx, data->mlx_win, 15, y += 20, 0xFFFFFF,
		"Rotate X: Drag Mouse Horizontal");
	mlx_string_put(data->mlx, data->mlx_win, 15, y += 20, 0xFFFFFF,
		"Rotate Y: Drag Mouse Vertical");
	mlx_string_put(data->mlx, data->mlx_win, 15, y += 20, 0xFFFFFF,
		"Rotate Z: < or >");
	mlx_string_put(data->mlx, data->mlx_win, 15, y += 20, 0xFFFFFF,
		"Flatten: + or -");
	mlx_string_put(data->mlx, data->mlx_win, 15, y += 20, 0xFFFFFF,
		"Translation/Move that shit: up, down, left and right arrow keys");
	mlx_string_put(data->mlx, data->mlx_win, 15, y += 20, 0xFFFFFF,
		"Quit: Esc");
}

int	render(t_data *data)
{
	if (data->mlx_win == NULL)
		return (-1);
	render_background(data->img, 0x0);
	plot_grid(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->mlx_img, 0, 0);
	print_menu(data);
	return (0);
}

void	plot_grid(t_data *data)
{
	int	i;

	project(data);
	i = -1;
	while (data->coor_2d[++i])
	{
		if (data->coor_2d[i + 1] != NULL && (i + 1) % data->width != 0)
			bresenhem(data, data->coor_2d[i], data->coor_2d[i + 1]);
		if ((i + data->width) < (data->width * data->height))
			bresenhem(data, data->coor_2d[i], data->coor_2d[i + data->width]);
	}
}
