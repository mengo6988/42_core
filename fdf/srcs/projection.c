/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:07:15 by mho               #+#    #+#             */
/*   Updated: 2024/01/16 16:31:18 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void rotate_x(int *x, int *y, int *z, double degree) {
  int prev_y;
  double rad;

  rad = RADIAN(degree);
  prev_y = *y;
  (void)x;
  *y = (prev_y * cos(rad)) + (sin(rad) * *z);
  *z = (-prev_y * sin(rad)) + (*z * cos(rad));
}

void rotate_y(int *x, int *y, int *z, double degree) {
  int prev_x;
  double rad;

  rad = RADIAN(degree);
  prev_x = *x;
  (void)y;
  *x = (prev_x * cos(rad)) + (sin(rad) * *z);
  *z = (-prev_x * sin(rad)) + (*z * cos(rad));
}

void rotate_z(int *x, int *y, int *z, double degree) {
  int prev_x;
  double rad;

  rad = RADIAN(degree);
  prev_x = *x;
  (void)z;
  *x = (prev_x * cos(rad)) - (sin(rad) * *y);
  *y = (prev_x * sin(rad)) + (*y * cos(rad));
}

void iso(int *x, int *y, int *z) {
  rotate_z(x, y, z, 50);
  rotate_x(x, y, z, -55);
}

void project(t_data *data) {
  int i;
  int x;
  int y;
  int z;

  i = -1;
  while (data->coor_3d[++i]) {
    x = data->coor_3d[i]->x * data->cam->zoom;
    y = data->coor_3d[i]->y * data->cam->zoom;
    z = data->coor_3d[i]->z * data->cam->zoom / data->cam->z_height;
    rotate_y(&x, &y, &z, data->cam->y_angle);
    rotate_x(&x, &y, &z, data->cam->x_angle);
    rotate_z(&x, &y, &z, data->cam->z_angle);
    if (data->cam->iso == 1)
      iso(&x, &y, &z);
    data->coor_2d[i]->x = x;
    data->coor_2d[i]->y = y;
    data->coor_2d[i]->x += data->cam->offset_x;
    data->coor_2d[i]->y += data->cam->offset_y;
    data->coor_2d[i]->color = data->coor_3d[i]->color;
  }
}
