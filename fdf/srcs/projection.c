/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:07:15 by mho               #+#    #+#             */
/*   Updated: 2024/01/15 21:00:22 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	rotate_x(int x, int y, int z, double degree)
// {
// 	int i;
// 	int prev_y;
// 	double rad;

// 	i = -1;
// 	rad = RADIAN(degree);
// 	while (data->coor_3d[++i])
// 	{
// 		y = data->coor_3d[i]->y;
// 		// data->coor_3d[i]->y = (y * cos(rad)) - (data->coor_3d[i]->z * sin(rad));
// 		// data->coor_3d[i]->z = (y * sin(rad)) + (data->coor_3d[i]->z * cos(rad));
// 		data->coor_3d[i]->y = (y * cos(rad)) + (data->coor_3d[i]->z * sin(rad));
// 		data->coor_3d[i]->z = (-y * sin(rad)) + (data->coor_3d[i]->z * cos(rad));
// 	}
// 	data->cam->x_angle = 0;
// }

void rotate_x(int *x, int *y, int *z, double degree)
{
	int prev_y;
	double rad;

	rad = RADIAN(degree);
	prev_y = *y;
	(void )x;
	*y = (prev_y * cos(rad)) + (sin(rad) * *z);
	*z = (-prev_y * sin(rad)) + (*z * cos(rad));
}

void rotate_y(int *x, int *y, int *z, double degree)
{
	int prev_x;
	double rad;

	rad = RADIAN(degree);
	prev_x = *x;
	(void )y;
	*x = (prev_x * cos(rad)) + (sin(rad) * *z);
	*z = (-prev_x * sin(rad)) + (*z * cos(rad));
}

void rotate_z(int *x, int *y, int *z, double degree)
{
	int prev_x;
	double rad;

	rad = RADIAN(degree);
	prev_x = *x;
	(void )z;
	*x = (prev_x * cos(rad)) - (sin(rad) * *y);
	*y = (prev_x * sin(rad)) + (*y * cos(rad));
}

// void	rotate_y(int x, int y, int z, double degree)
// {
// 	int i;
// 	int x;
// 	double rad;

// 	i = -1;
// 	rad = RADIAN(degree);
// 	while (data->coor_3d[++i])
// 	{
// 		x = data->coor_3d[i]->x;
// 		data->coor_3d[i]->x = (x * cos(rad)) + (data->coor_3d[i]->z * sin(rad));
// 		data->coor_3d[i]->z = (-x * sin(rad)) + (data->coor_3d[i]->z * cos(rad));
// 	}
// 	data->cam->y_angle = 0;
// }

// void	rotate_z(int x, int y, int z, double degree)
// {
// 	int i;
// 	int x;
// 	double rad;

// 	i = -1;
// 	rad = RADIAN(degree);
// 	while (data->coor_3d[++i])
// 	{
// 		x = data->coor_3d[i]->x;
// 		data->coor_3d[i]->x = (x * cos(rad)) - (data->coor_3d[i]->y * sin(rad));
// 		data->coor_3d[i]->y = (x * sin(rad)) + (data->coor_3d[i]->y * cos(rad));
// 	}
// 	data->cam->z_angle = 0;
// }

void	iso(int *x, int *y, int *z)
{
	rotate_z(x, y, z, 50);
	rotate_x(x, y, z, -55);
	// rotate_x(x, y, z, -55);
	// int prex;
	// int prey;

	// prex = *x;
	// prey = *y;
	// *x = (prex - prey) * cos(30);
	// *y = -*z + (prex + prey) * sin(30);
}
// *x = (previous_x - previous_y) * cos(0.523599);
// 	*y = -z + (previous_x + previous_y) * sin(0.523599);
void	project(t_data *data)
{
	int	i;
	int x;
	int y;
	int z;

	i = -1;
	while (data->coor_3d[++i])
	{
		x = data->coor_3d[i]->x * data->cam->zoom;
		y = data->coor_3d[i]->y * data->cam->zoom;
		z = data->coor_3d[i]->z * data->cam->zoom / data->cam->z_height;
		rotate_y(&x, &y ,&z, data->cam->y_angle);
		rotate_x(&x, &y ,&z, data->cam->x_angle);
		rotate_z(&x, &y ,&z, data->cam->z_angle);
		if (data->cam->iso == 1)
			iso(&x, &y, &z);
		// else
		// {
		// 	data->coor_2d[i]->x = x;
		// 	data->coor_2d[i]->y = y;
		// }
		data->coor_2d[i]->x = x;
		data->coor_2d[i]->y = y;
		// data->coor_2d[i]->x += data->cam->offset_x - ((data->cam->zoom * data->width) / 2);
		// data->coor_2d[i]->y += data->cam->offset_y - ((data->cam->zoom * data->height) /2);
		data->coor_2d[i]->x += data->cam->offset_x;
		data->coor_2d[i]->y += data->cam->offset_y;
		data->coor_2d[i]->color = data->coor_3d[i]->color;
		// ft_printf("x: %i, y: %i\n", data->cam->x_angle, data->cam->y_angle);
	}
}

