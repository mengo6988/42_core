/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:04:35 by mho               #+#    #+#             */
/*   Updated: 2024/01/17 08:28:34 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_down(int key, int x, int y, void *param)
{
	t_data	*data;

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

int	mouse_up(int key, int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	(void)x;
	(void)y;
	if (key == MOUSE_LEFT_BUTTON)
		data->mouse->is_pressed = 0;
	return (0);
}

int	mouse_move(int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->mouse->is_pressed == 1)
	{
		data->cam->x_angle += (x - data->mouse->x) * 0.3;
		data->cam->y_angle += (y - data->mouse->y) * 0.3;
	}
	data->mouse->x = x;
	data->mouse->y = y;
	return (0);
}

void	controls_hook(t_data *data)
{
	mlx_hook(data->mlx_win, EVENT_DESTROY, 0, on_destroy, data);
	mlx_hook(data->mlx_win, EVENT_KEYDOWN, 0, key_press, data);
	mlx_hook(data->mlx_win, EVENT_MOUSEDOWN, 0, mouse_down, data);
	mlx_hook(data->mlx_win, EVENT_MOUSEUP, 0, mouse_up, data);
	mlx_hook(data->mlx_win, EVENT_MOUSEMOVE, 0, mouse_move, data);
}

int	key_press(int key, void *param)
{
	t_data	*data;

	data = param;
	if (key == KEY_ESC)
		on_destroy(data);
	else if (key == KEY_DOWN || key == KEY_UP || key == KEY_LEFT
		|| key == KEY_RIGHT)
		move_image(key, data);
	else if (key == KEY_LESS || key == KEY_MORE)
		z_rotation(key, data);
	else if (key == KEY_PLUS || key == KEY_MINUS)
		change_tallness(key, data);
	else if (key == KEY_I)
	{
		if (data->cam->iso == 1)
			data->cam->iso = 0;
		else
			data->cam->iso = 1;
	}
	return (0);
}
