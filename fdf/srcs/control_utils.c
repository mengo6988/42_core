/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:41:23 by mho               #+#    #+#             */
/*   Updated: 2024/01/16 16:19:30 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	on_destroy(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	free_all(data);
	exit(0);
}

void	move_image(int key, t_data *data)
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

void	change_tallness(int key, t_data *data)
{
	if (key == KEY_PLUS & data->cam->z_height > 1)
		data->cam->z_height -= 1;
	else if (key == KEY_MINUS)
		data->cam->z_height += 1;
}
