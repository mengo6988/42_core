/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:04:35 by mho               #+#    #+#             */
/*   Updated: 2024/01/15 20:58:56 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void free_all(t_data *data)
{
	int i;

	free(data->mouse);
	free(data->cam);
	free(data->img);
	i = -1;
	while (++i < data->height * data->width)
	{
		free(data->coor_2d[i]);
		free(data->coor_3d[i]);
	}
	free(data->coor_2d);
	free(data->coor_3d);
	free(data->mlx);
}

int mouse_down(int key, int x, int y, void *param)
{
	t_data *data;

	data = (t_data *)param;

	if (key == MOUSE_LEFT_BUTTON)
		data->mouse->is_pressed = 1;
	if (key == MOUSE_SCROLL_DOWN && data->cam->zoom > 1)
		data->cam->zoom--;
	else if (key == MOUSE_SCROLL_UP)
		data->cam->zoom++;
	(void)x;
	(void)y;
	return (0);
}

int mouse_up(int key, int x, int y, void *param)
{
	t_data *data;

	data = (t_data *)param;
	(void)x;
	(void)y;
	if (key == MOUSE_LEFT_BUTTON)
		data->mouse->is_pressed = 0;
	return (0);
}

int mouse_move(int x, int y, void *param)
{
	t_data *data;

	data = (t_data *)param;
	if (data->mouse->is_pressed == 1)
	{
		data->cam->x_angle += (x - data->mouse->x) * 0.3;
		data->cam->y_angle += (y - data->mouse->y) * 0.3;
		// rotate_x(data, (double)(x - data->mouse->x));
		// rotate_y(data, (double)(y - data->mouse->y));
	}
	data->mouse->x = x;
	data->mouse->y = y;
	return (0);
}

int	on_destroy(void *param)
{
	t_data *data;
	data = (t_data *)param;
	data->mlx_win = NULL;
	free_all(data);
	exit(0);
}

void move_image(int key, t_data *data)
{
	if (key == KEY_UP)
		data->cam->offset_y -= 10;
	else if (key == KEY_DOWN)
		data->cam->offset_y += 10;
	else if (key == KEY_RIGHT)
		data->cam->offset_x += 10;
	else if (key == KEY_LEFT)
		data->cam->offset_x -= 10;
}

void	z_rotation(int key, t_data *data)
{
	if (key == KEY_LESS)
		data->cam->z_angle -= 1;
	else if (key == KEY_MORE)
		data->cam->z_angle += 1;
}

void change_tallness(int key, t_data *data)
{
	if (key == KEY_PLUS & data->cam->z_height > 1)
		data->cam->z_height -= 1;
	else if (key == KEY_MINUS)
		data->cam->z_height += 1;
}

int key_press(int key, void *param)
{
	t_data *data;

	data = param;
	if (key == KEY_ESC)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		on_destroy(data);
	}
	else if (key == KEY_DOWN || key == KEY_UP || key == KEY_LEFT || key == KEY_RIGHT)
		move_image(key, data);
	else if (key == KEY_LESS || key == KEY_MORE)
		z_rotation(key, data);
	else if (key == KEY_PLUS || key == KEY_MINUS)
		change_tallness(key, data);
	return (0);
}

void	controls_hook(t_data *data)
{
	mlx_hook(data->mlx_win, EVENT_DESTROY, 0, on_destroy, data);
	mlx_hook(data->mlx_win, EVENT_KEYDOWN, 0, key_press, data);
	// mlx_hook(data->mlx_win, EVENT_KEYUP, 0, on_destroy, data);
	mlx_hook(data->mlx_win, EVENT_MOUSEDOWN, 0, mouse_down, data);
	mlx_hook(data->mlx_win, EVENT_MOUSEUP, 0, mouse_up, data);
	mlx_hook(data->mlx_win, EVENT_MOUSEMOVE, 0, mouse_move, data);
}

// 	mlx_string_put(mlx, win, 65, y += 20, TEXT_COLOR, "How to Use");
// int	mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color,
// 		       char *string);
