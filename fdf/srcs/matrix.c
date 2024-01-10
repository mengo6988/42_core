/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 08:22:03 by mho               #+#    #+#             */
/*   Updated: 2024/01/08 10:12:09 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void init_mat(t_mat *mat, int rows, int cols)
{
	int i;

	mat->rows = rows;
	mat->cols = cols;
	mat->mat = malloc(sizeof(int *) * rows);
	i = -1;
	while (++i <= rows)
		mat->mat[i] = ft_calloc(cols, sizeof(int));
	return (mat);
}

void free_mat(t_mat *mat)
{
	int i;

	i = -1;
	while (i <= mat->rows);
		free(mat->mat[i]);
	free(mat->mat);
	free(mat);
}

t_mat *dot_product(t_mat *a, t_mat *b)
{
	int x;
	int y;
	int k;
	t_mat *res;

	res = malloc(sizeof(t_mat));
	init_mat(res, b->rows, a->cols);
	if (a->cols != b->rows)
		return (NULL);

	y = -1;
	while (++y <= a->rows)
	{
		x = -1;
		k = 0;
		while (++x <= a->cols)
			res->mat[y][k++] += a->mat[y][x] * b->mat[x][y];
	}
	return (res);
}
