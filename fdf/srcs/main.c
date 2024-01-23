/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 08:05:01 by mho               #+#    #+#             */
/*   Updated: 2024/01/16 16:27:59 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_cam	*cam_init(t_data *data)
{
	t_cam	*res;
	int		zoomx;
	int		zoomy;

	res = malloc(sizeof(t_cam));
	zoomx = round((WINDOW_WIDTH / data->width) / 2);
	zoomy = round((WINDOW_HEIGHT / data->height) / 2);
	res->z_height = 1;
	if (zoomx < zoomy)
		res->zoom = zoomx;
	else
		res->zoom = zoomy;
	res->offset_x = (WINDOW_WIDTH - (data->width)) - 600;
	res->offset_y = (WINDOW_HEIGHT - (data->height)) - 300;
	res->x_angle = 0;
	res->y_angle = 0;
	res->z_angle = 0;
	res->iso = 1;
	return (res);
}

t_mouse	*mouse_init(void)
{
	t_mouse	*mouse;

	mouse = malloc(sizeof(t_mouse));
	mouse->is_pressed = 0;
	mouse->x = 0;
	mouse->y = 0;
	return (mouse);
}

void	data_init(t_data *data, char **av)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		ft_error("MLX");
	data->mlx_win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
			"FDF");
	if (!data->mlx_win)
		ft_error("MLX WIN");
	data->img = malloc(sizeof(t_img));
	data->img->mlx_img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->mlx_img,
			&data->img->bits_per_pixel, &data->img->line_len,
			&data->img->endian);
	data->coor_3d = load_coor(av[1], data);
	data->coor_2d = malloc(sizeof(t_2d *) * ((data->height * data->width) + 1));
	data->cam = cam_init(data);
	data->mouse = mouse_init();
	adjust_coor(data);
}

void	adjust_coor(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->height * data->width)
		data->coor_2d[i] = malloc(sizeof(t_2d));
	data->coor_2d[i] = NULL;
	i = -1;
	while (data->coor_3d[++i])
	{
		data->coor_3d[i]->x -= data->width / 2;
		data->coor_3d[i]->y -= data->height / 2;
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		ft_error("invalid arguments");
	data_init(&data, av);
	mlx_loop_hook(data.mlx, &render, &data);
	controls_hook(&data);
	mlx_hook(data.mlx_win, EVENT_MOUSEDOWN, 0, mouse_down, &data);
	mlx_loop(data.mlx);
}
