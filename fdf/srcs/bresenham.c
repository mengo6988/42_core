/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:05:45 by mho               #+#    #+#             */
/*   Updated: 2024/01/10 22:33:35 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plot(int x, int y, int color, t_data *data)
{
	if ((x >= 0 && x < WINDOW_WIDTH) && (y < WINDOW_HEIGHT && y >= 0) && data->img->addr)
		my_mlx_pix_put(data->img, x, y, color);
}

void	bresenhem_low(t_data *data, t_2d *p1, t_2d *p2)
{
	int dy;
	int d;
	int yi;
	int x;
	int y;

	dy = ABS(p2->y - p1->y);
	yi = 1;
	if ((p2->y - p1->y) < 0)
		yi = -1;
	d = (2 * dy) - (p2->x - p1->x);
	x = p1->x;
	y = p1->y;
	while (x <= p2->x)
	{
		plot(x, y, get_color(p1->color, p2->color, (p2->x - p1->x), (p1->x - x)), data);
		if (d > 0)
		{
			y = y + yi;
			d += (2 * (dy - (p2->x - p1->x)));
		}
		else
			d = d + (2 * dy);
		x++;
	}
}

void	bresenhem_high(t_data *data, t_2d *p1, t_2d *p2)
{
	int dx;
	int d;
	int xi;
	int y;
	int x;

	dx = ABS(p2->x - p1->x);
	xi = 1;
	if ((p2->x - p1->x) < 0)
		xi = -1;
	d = (2 * dx) - (p2->y - p1->y);
	y = p1->y;
	x = p1->x;
	while (y <= p2->y)
	{
		plot(x, y, get_color(p1->color, p2->color, (p2->y - p1->y), (y - p1->y)), data);
		if (d > 0)
		{
			x = x + xi;
			d += 2 * (dx - (p2->y - p1->y));
		}
		else
			d = d + (2 * dx);
		y++;
	}
}

void	bresenhem(t_data *data, t_2d *a, t_2d *b)
{
	int dy;
	int dx;

	dy = b->y - a->y;
	dx = b->x - a->x;
	if (ABS(dy) < ABS(dx))
	{
		if (dx < 0)
			bresenhem_low(data, b, a);
		else
			bresenhem_low(data, a, b);
	}
	else
	{
		if (dy < 0)
			bresenhem_high(data, b, a);
		else
			bresenhem_high(data, a, b);
	}
}
