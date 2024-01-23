/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:23:22 by mho               #+#    #+#             */
/*   Updated: 2024/01/17 08:27:30 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



int	get_color(int start, int end, int length, int current)
{
	int		res;
	int	increment[3];
	int		new[3];

	increment[0] = (double)((R(end)) - (R(start))) / (double)length;
	increment[1] = (double)((G(end)) - (G(start))) / (double)length;
	increment[2] = (double)((B(end)) - (B(start))) / (double)length;
	new[0] = round((increment[0] * current)) + (R(start));
	new[1] = round((increment[1] * current)) + (G(start));
	new[2] = round((increment[2] * current)) + (B(start));
	res = RGB(new[0], new[1], new[2]);
	return (res);
}
