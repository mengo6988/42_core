/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:07:15 by mho               #+#    #+#             */
/*   Updated: 2024/01/10 16:44:15 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(t_data *data)
{
	int	i;

	i = -1;
	while (data->coor_3d[++i])
	{
		// data->coor_2d[i]->x = (int)round((data->coor_3d[i]->x - data->coor_3d[i]->z)
		// 	/ sqrt(2)) + 300;
		// data->coor_2d[i]->y = (int)round(((data->coor_3d[i]->x + (data->coor_3d[i]->y * 2)
		// 	+ data->coor_3d[i]->z) / sqrt(6))) + 150;

	// data->coor_2d[i]->x = (int)round((data->coor_3d[i]->x - data->coor_3d[i]->z * cos(108.43)) / sqrt(2)) + 300;
	// data->coor_2d[i]->y = (int)round((data->coor_3d[i]->x * sin(108.43) + data->coor_3d[i]->y * sin(108.43) * 2 + data->coor_3d[i]->z * sin(108.43)) / sqrt(6)) + 150;

		data->coor_2d[i]->x = (data->coor_3d[i]->x - data->coor_3d[i]->y) * cos(0.523599) + 350;
		data->coor_2d[i]->y = (- data->coor_3d[i]->z + (data->coor_3d[i]->x + data->coor_3d[i]->y) * sin(0.523599)) + 350;
		//test

		// data->coor_2d[i]->x = (data->coor_3d[i]->x * cos(45)) - (data->coor_3d[i]->y * sin(45));
		// data->coor_2d[i]->y = (data->coor_3d[i]->y * cos(45)) + (data->coor_3d[i]->x * sin(45));
		// data->coor_2d[i]->x = (data->coor_2d[i]->x * cos(35.264)) + (data->coor_3d[i]->z * sin(35.364));
		//-----------------
		// data->coor_2d[i]->x = (data->coor_3d[i]->x - data->coor_3d[i]->y) * cos(0.523599);
		// data->coor_2d[i]->y = -data->coor_3d[i]->z + (data->coor_3d[i]->x + data->coor_3d[i]->y) * sin(0.523599);
		// data->coor_2d[i]->x += 300;
		// data->coor_2d[i]->y += 300;
		// data->coor_2d[i]->x = (data->coor_3d[i]->x * cos(30.0)) - (data->coor_3d[i]->y * sin(30.0));
		// data->coor_2d[i]->y = (data->coor_3d[i]->y * cos(30.0)) + (data->coor_3d[i]->x * sin(30.0));
	}
	// data->coor_2d[0]->x = 300;
	// data->coor_2d[0]->y = 300;
	// data->coor_2d[1]->x = 600;
	// data->coor_2d[1]->y = 600;
}
