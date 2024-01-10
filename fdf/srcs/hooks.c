/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:14:43 by mho               #+#    #+#             */
/*   Updated: 2024/01/03 17:12:21 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int mouse_event(int keycode, int x, int y, t_data *data)
{
	// data->line = malloc(sizeof(t_line));
	// data->line->x0 = WINDOW_WIDTH/2;
	// data->line->y0 = WINDOW_HEIGHT/2;
	data->line->x1 = x;
	data->line->y1 = y;
	if (data->mlx_win == NULL)
		return (-1);
	if (keycode == 1)
		ft_printf("x: %i, y: %i\n", x, y);
	return (0);
}
