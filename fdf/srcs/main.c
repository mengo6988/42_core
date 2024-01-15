/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 08:05:01 by mho               #+#    #+#             */
/*   Updated: 2024/01/15 21:01:29 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int handle_keypress(int keysym, t_data *data)
{
	if (keysym == 53)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		data->mlx_win = NULL;
		free(data->mlx);
		exit(0);
	}
	return (0);
}

void my_mlx_pix_put(t_img *img, int x, int y, int color)
{
	char *pixel;

	if ((x >= 0 && x < WINDOW_WIDTH) && (y <= WINDOW_HEIGHT && y >= 0))
	{
		pixel = img->addr + (y * img->line_len + x * (img->bits_per_pixel/ 8));
		*(unsigned int*)pixel = color;
	}
}

void render_background(t_img *img, int color)
{
	int i;
	int j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			my_mlx_pix_put(img, j++, i, color);
		i++;
	}
}

int render_rect(t_img *img, t_rect rect)
{
	int i;
	int j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			my_mlx_pix_put(img, j++, i, rect.color);
		i++;
	}
	return (0);
}

void	plot_grid(t_data *data)
{
	int i;

	project(data);
	i = -1;
	while (data->coor_2d[++i])
	{
		if (data->coor_2d[i + 1] != NULL && (i + 1) % data->width != 0)
			bresenhem(data, data->coor_2d[i], data->coor_2d[i + 1]);
		// if (data->coor_2d[i + data->width] != NULL)
		if ((i + data->width) < (data->width *data->height))
			bresenhem(data, data->coor_2d[i], data->coor_2d[i + data->width]);
	}
	// t_2d *a = malloc(sizeof(t_2d));
	// t_2d *b = malloc(sizeof(t_2d));
	// a->x = 600;
	// a->y = 500;
	// b->x = 900;
	// b->y = 750;
	// bresenham(data, a, b);
}

void test_line(t_data *data)
{
	t_2d a;
	t_2d a1;
	t_2d a2;
	t_2d a3;
	t_2d a4;
	t_2d a5;
	t_2d a6;
	t_2d a7;
	t_2d a8;
	t_2d a12;
	t_2d a11;
	t_2d a10;
	t_2d a9;

	a.x = 500;
	a.y = 500;
	a1.x = 100;
	a1.y =100;
	a2.x = 500;
	a2.y = 100;
	a3.x = 1000;
	a3.y = 100;
	a4.x = 100;
	a4.y = 500;
	a5.x = 1000;
	a5.y = 500;
	a6.x = 100;
	a6.y = 1000;
	a7.x = 500;
	a7.y = 1000;
	a8.x = 1000;
	a8.y = 1000;
	a9.x = 250;
	a9.y = 100;
	a10.x = 750;
	a10.y = 100;
	a11.x = 250;
	a11.y = 1000;
	a12.x = 750;
	a12.y = 1000;
	bresenhem(data, &a, &a1);
	a.x = 500;
	a.y = 500;
	bresenhem(data, &a, &a2);
	a.x = 500;
	a.y = 500;
	bresenhem(data, &a, &a3);
	a.x = 500;
	a.y = 500;
	bresenhem(data, &a, &a4);
	a.x = 500;
	a.y = 500;
	bresenhem(data, &a, &a5);
	a.x = 500;
	a.y = 500;
	bresenhem(data, &a, &a6);
	a.x = 500;
	a.y = 500;
	bresenhem(data, &a, &a7);
	a.x = 500;
	a.y = 500;
	bresenhem(data, &a, &a8);
	a.x = 500;
	a.y = 500;
	bresenhem(data, &a, &a9);
	a.x = 500;
	a.y = 500;
	bresenhem(data, &a, &a10);
	a.x = 500;
	a.y = 500;
	bresenhem(data, &a, &a11);
	a.x = 500;
	a.y = 500;
	bresenhem(data, &a, &a12);
}

void	print_menu(t_data *data)
{
	int y;

	y = 0;
	mlx_string_put(data->mlx, data->mlx_win, 15, y+=20, 0xFFFFFF, "Tutorial");
	mlx_string_put(data->mlx, data->mlx_win, 15, y+=20, 0xFFFFFF, "Zoom: Scroll");
	mlx_string_put(data->mlx, data->mlx_win, 15, y+=20, 0xFFFFFF, "Rotate X: Drag Mouse Horizontal");
	mlx_string_put(data->mlx, data->mlx_win, 15, y+=20, 0xFFFFFF, "Rotate Y: Drag Mouse Vertical");
	mlx_string_put(data->mlx, data->mlx_win, 15, y+=20, 0xFFFFFF, "Rotate Z: < or >");
	mlx_string_put(data->mlx, data->mlx_win, 15, y+=20, 0xFFFFFF, "Flatten: + or -");
	mlx_string_put(data->mlx, data->mlx_win, 15, y+=20, 0xFFFFFF, "Translation/Move that shit: up, down, left and right arrow keys");
	mlx_string_put(data->mlx, data->mlx_win, 15, y+=20, 0xFFFFFF, "Quit: Esc");
}

int render(t_data *data)
{
	// ft_printf("dx: %i, dy: %i\n)");
	// data->line = line;
	if (data->mlx_win == NULL)
		return (-1);
	render_background(data->img, 0x0);
	plot_grid(data);
	// ft_printf("%i %i %i\n", data->coor_3d[0]->x, data->coor_3d[0]->y, data->coor_3d[0]->z);
	// test_line(data);
	// render_rect(&data->img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100, 100, 100, 0xFF0000});
	// render_rect(&data->img, (t_rect){0, 0, 100, 100, 0xFFFF00});
	// if (data->line != NULL)
	// 	bresenhem(data);
	// for (int i = 0; i < WINDOW_WIDTH; i++) {
	// 	my_mlx_pix_put(&data->img, i, WINDOW_HEIGHT / 2, 0xFFFFFF);
	// }
	// for (int y = 450; y <= 550; y++)
	// {
	// 	for (int x = 550; x <= 650; x++)
	// 		my_mlx_pix_put(data->img, x, y, 0xFFFF00);
	// }
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->mlx_img, 0, 0);
	print_menu(data);
	// ft_printf("rendering\n");
	return (0);
}


int key_hook(int keycode, t_data *data)
{
	if (data->mlx_win == NULL)
		return (-1);
	ft_printf("hello from keyhook = %i\n", keycode);
	// data->mlx;
	// data->mlx_win;
	return (0);
}

// int main(void)
// {
	// t_data data;

	// data.mlx = mlx_init();
	// data.line = NULL;
	// if (data.mlx == NULL)
	// 	return (-1);
	// data.mlx_win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "TEST");
	// if (data.mlx_win == NULL)
	// {
	// 	free(data.mlx_win);
	// 	return (-1);
	// }
	// data.img.mlx_img = mlx_new_image(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	// data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bits_per_pixel, &data.img.line_len, &data.img.endian);
	// mlx_loop_hook(data.mlx, &render, &data);
	// // render(&data);
	// mlx_hook(data.mlx_win, 02, 0L, &handle_keypress, &data);
	// // mlx_mouse_hook(data.mlx_win, mouse_event, &data);
	// mlx_key_hook(data.mlx_win, &key_hook, &data);
	// mlx_loop(data.mlx);

	// // mlx_destroy_window(data.mlx, data.mlx_win);
	// free(data.mlx);
	// exit(0);
// }

t_cam *cam_init(t_data *data)
{
	t_cam *res;
	int zoomx;
	int zoomy;

	res = malloc(sizeof(t_cam));
	zoomx = round((WINDOW_WIDTH / data->width) / 2);
	zoomy = round((WINDOW_HEIGHT / data->height) / 2);
	res->z_height = 1;
	if (zoomx < zoomy)
		res->zoom = zoomx;
	else
		res->zoom = zoomy;
	res->offset_x = (WINDOW_WIDTH - (data->width)) - 600;
	res->offset_y = (WINDOW_HEIGHT - (data->height)) - 300;
	res->x_angle = 0;
	res->y_angle = 0;
	res->z_angle = 0;
	res->iso = 1;
	return (res);
}

t_mouse *mouse_init(void)
{
	t_mouse *mouse;

	mouse = malloc(sizeof(t_mouse));
	mouse->is_pressed = 0;
	mouse->x = 0;
	mouse->y = 0;
	return (mouse);
}

void data_init(t_data *data, char **av)
{
	int i;

	data->mlx = mlx_init();
	if (data->mlx == NULL)
		ft_error("MLX");
	data->mlx_win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	if (!data->mlx_win)
		ft_error("MLX WIN");
	data->img = malloc(sizeof(t_img));
	data->img->mlx_img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->mlx_img, &data->img->bits_per_pixel, &data->img->line_len, &data->img->endian);
	data->coor_3d = load_coor(av[1], data);
	data->coor_2d = malloc(sizeof(t_2d *) * ((data->height * data->width) + 1));
	data->cam = cam_init(data);
	data->mouse = mouse_init();
	i = -1;
	while (++i < data->height * data->width)
	{
		data->coor_2d[i] = malloc(sizeof(t_2d));
		data->coor_3d[i]->x -= data->width / 2;
		data->coor_3d[i]->y -= data->height / 2;
	}
	data->coor_2d[i] = NULL;
}

int main(int ac, char **av)
{
	t_data data;
	if (ac != 2)
		ft_error("invalid arguments");
	data_init(&data, av);
	// int i = 0;
	// while (data.coor_2d[i] != NULL)
	// {
	// 	ft_printf("%i, %i |", data.coor_2d[i]->x, data.coor_2d[i]->y);
	// 	i++;
	// 	if (i % data.width == 0)
	// 		ft_printf("\n");
	// }
	mlx_loop_hook(data.mlx, &render, &data);
	// mlx_hook(data.mlx_win, 02, 0L, &handle_keypress, &data);
	controls_hook(&data);
	mlx_hook(data.mlx_win, EVENT_MOUSEDOWN, 0, mouse_down, &data);
	mlx_key_hook(data.mlx_win, &key_hook, &data);
	mlx_loop(data.mlx);
	// for (int i = 0; i < (data.width * data.height);i++)
	// 	ft_printf("%i, %i: %x \n", data.coor_2d[i]->x, data.coor_2d[i]->y, data.coor_2d[i]->color);
}

// int main(void)
// {
// 	t_2d a;
// 	t_2d b;
// 	t_data *data = NULL;

// 	a.x = 500;
// 	a.y = 500;
// 	b.x = 100;
// 	b.y = 1000;
// 	if (data == NULL)
// 		bresenhem(data, &a, &b);
// }
