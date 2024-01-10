/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:05:45 by mho               #+#    #+#             */
/*   Updated: 2024/01/10 16:32:40 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plot(int x, int y, t_data *data)
{
	if ((x >= 0 && x < WINDOW_WIDTH) && (y < WINDOW_HEIGHT && y >= 0) && data->img->addr)
		my_mlx_pix_put(data->img, x, y, 0xFFFFF0);
	// if (data == NULL)
	// 	ft_printf("test bresenham coors (%i, %i)\n", x, y);
}

void	bresenhem_low(t_data *data, t_2d *p1, t_2d *p2)
{
	int dx;
	int dy;
	int d;
	int yi;
	int x;
	int y;

	// ft_printf("running low\n");
	dx = p2->x - p1->x;
	dy = ABS(p2->y - p1->y);
	// ft_printf("%i\n", dy);
	yi = 1;
	if ((p2->y - p1->y) < 0)
		yi = -1;
	d = (2 * dy) - dx;
	x = p1->x;
	y = p1->y;
	while (x <= p2->x)
	{
		plot(x, y, data);
		if (d > 0)
		{
			y = y + yi;
			d = d + (2 * (dy - dx));
		}
		else
			d = d + (2 * dy);
		x++;
	}
}

void	bresenhem_high(t_data *data, t_2d *p1, t_2d *p2)
{
	int dx;
	int dy;
	int d;
	int xi;
	int y;
	int x;

	// ft_printf("running high\n");
	dx = ABS(p2->x - p1->x);
	dy = p2->y - p1->y;
	xi = 1;
	if ((p2->x - p1->x) < 0)
		xi = -1;
	d = (2 * dx) - dy;
	y = p1->y;
	x = p1->x;
	while (y <= p2->y)
	{
		plot(x, y, data);
		if (d > 0)
		{
			x = x + xi;
			d = d + (2 * (dx - dy));
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

// int main(void) {
// 	int x = 0;
// 	int y = 0;
// 	int data->line->x1 = 3;
// 	int data->line->y1 = 8;

// 	ft_printf("running\n");
// 	bresenhem(x, y, data->line->x1, data->line->y1);
// 	return (0);
// }

// int compare(int a, int b)
// {
// 	if (a < b)
// 		return (1);
// 	else
// 		return (-1);
// }

// t_line *init_line(t_2d *a, t_2d *b)
// {
// 	t_line *line;

// 	line = malloc(sizeof(t_line));
// 	line->dx = ABS(b->x - a->x);
// 	line->sx = compare(a->x, b->x);
// 	line->dy = ABS(b->y - a->y);
// 	line->sy =compare(a->y, b->y);
// 	line->err = line->dx + line->dy;
// 	return (line);
// }

// void	bs(t_data *data, t_2d *a, t_2d *b)
// {
// 	t_line *line;

// 	line = init_line(a, b);
// 	while (1)
// 	{
// 		plot(a->x, a->y, data);
// 		if (a->x == b->x && a->y == b->y)
// 			break;
// 		line->e2 = 2 * line->err;
// 		if (line->e2 >= line->dy)
// 		{
// 			line->err += line->dy;
// 			a->x += line->sx;
// 		}
// 		if (line->e2 <= line->dx)
// 		{
// 			line->err += line->dx;
// 			a->y += line->sy;
// 		}
// 	}
// 	free(line);
// }

// void bresenham(t_data *data, t_2d *p1, t_2d *p2)
// {
// 	int x1 = p1->x;
// 	int y1 = p1->y;
// 	int x2 = p2->x;
// 	int y2 = p2->y;
// 	int rise = y2 - y1;
// 	int run = x2 - x1;
// 	if (run == 0)
// 	{
// 		if (y2 < y1)
// 		{
// 			y1 = p2->y;
// 			y2 = p1->y;
// 		}
// 		while (y1 <= y2)
// 			plot(x1, y1++, data);
// 	}
// 	else
// 	{
// 		int m = rise / run;
// 		int adjust = m >= 0 ? 1 : -1;
// 		int offset = 0;
// 		if (m <= 1 && m >= -1)
// 		{
// 			int threshold = ABS(run);
// 			int delta = ABS(rise) * 2;
// 			int thresholdinc = ABS(run) * 2;
// 			int y = y1;
// 			if (x2 < x1)
// 			{
// 				x2 = p1->x;
// 				x1 = p2->x;
// 				y = y2;
// 			}
// 			while (x1 <= x2)
// 			{
// 				plot(x1++, y, data);
// 				offset += delta;
// 				if (offset >= threshold)
// 				{
// 					y += adjust;
// 					threshold += thresholdinc;
// 				}
// 			}
// 		}
// 		else
// 		{
// 			int delta = ABS(run) * 2;
// 			int threshold = ABS(rise);
// 			int thresholdinc = ABS(rise) * 2;
// 			int x = x1;
// 			if (y2 < y1)
// 			{
// 				y1 = p2->y;
// 				y2 = p1->y;
// 				x = x2;
// 			}
// 			while (y1 <= y2)
// 			{
// 				plot(x, y1++, data);
// 				offset += delta;
// 				if (offset >= threshold)
// 				{
// 					x += adjust;
// 					threshold += thresholdinc;
// 				}
// 			}
// 		}

// 	}
// }

// void	draw_line(t_data *fdf, t_2d *start, t_2d *end )
// {
// 	t_2d	delta;
// 	t_2d	sign;
// 	t_2d	*cur;
// 	int		error[2];

// 	delta.x = ABS(end->x - start->x);
// 	delta.y = ABS(end->y - start->y);
// 	sign.x = start->x < end->x ? 1 : -1;
// 	sign.y = start->y < end->y ? 1 : -1;
// 	error[0] = delta.x - delta.y;
// 	cur = start;
// 	while (cur->x != end->x || cur->y != end->y)
// 	{
// 		plot(cur->x, cur->y, fdf);
// 		if ((error[1] = error[0] * 2) > -delta.y)
// 		{
// 			error[0] -= delta.y;
// 			cur->x += sign.x;
// 		}
// 		if (error[1] < delta.x)
// 		{
// 			error[0] += delta.x;
// 			cur->y += sign.y;
// 		}
// 	}
// }

// void draw_line_major(t_data *data, int dy, int dx, t_2d *start)
// {
// 	int err;
// 	int yi;

// 	yi = 1;
// 	if (dy < 0)
// 	{
// 		dy = ABS(dy);
// 		yi *= -1;
// 	}
// 	err = (2 * dy) - dx;
// 	while (dx)
// 	{
// 		plot(start->x, start->y, 0xFFFFFF);
// 		if (err > 0)
// 		{
// 			err += 2 * (dy - dx);
// 			start->y += yi;
// 		}
// 		else
// 			err += 2 * dy;
// 		start->x++;
// 		dx--;
// 	}
// }

// void draw_line_single(t_data * data, int dy, int dx, t_2d *start)
// {
// 	while (dx)
// 	{
// 		start->
// 	}
// }
