/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 08:05:20 by mho               #+#    #+#             */
/*   Updated: 2024/01/16 16:34:16 by mho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>

# define WINDOW_HEIGHT 1000
# define WINDOW_WIDTH 1200
# define ABS(Value) ((Value < 0) ? -(Value) : (Value))
# define BASE "0123456789ABCDEF"
# define R(a) (a) >> 16
# define G(a) ((a) >> 8) & 0xFF
# define B(a) (a) & 0xFF
# define RGB(r, g, b) ((r) << 16) + ((g) << 8) + (b)
# define RADIAN(degrees) (degrees) * (M_PI / 180.0)

# define TEXT_COLOR 0xEAEAEA
# define BACKGROUND 0x222222
# define MENU_BACKGROUND 0x1E1E1E

# define COLOR_DISCO 0x9A1F6A
# define COLOR_BRICK_RED 0xC2294E
# define COLOR_FLAMINGO 0xEC4B27
# define COLOR_JAFFA 0xEF8633
# define COLOR_SAFFRON 0xF3AF3D

# define EVENT_KEYDOWN 02
# define EVENT_KEYUP 03
# define EVENT_MOUSEDOWN 04
# define EVENT_MOUSEUP 05
# define EVENT_MOUSEMOVE 06
# define EVENT_DESTROY 17

# define MOUSE_LEFT_BUTTON 1
# define MOUSE_RIGHT_BUTTON 2
# define MOUSE_THIRD_BUTTON 3
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5
# define MOUSE_SCROLL_LEFT 6
# define MOUSE_SCROLL_RIGHT 7

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define NUM_PAD_0 82
# define NUM_PAD_1 83
# define NUM_PAD_2 84
# define NUM_PAD_3 85
# define NUM_PAD_4 86
# define NUM_PAD_5 87
# define NUM_PAD_6 88
# define NUM_PAD_7 89
# define NUM_PAD_8 91
# define NUM_PAD_9 92
# define NUM_PAD_PLUS 69
# define NUM_PAD_MINUS 78

# define KEY_ESC 53
# define KEY_I 34
# define KEY_P 35
# define KEY_0 29
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
# define KEY_4 21
# define KEY_5 23
# define KEY_6 22
# define KEY_7 26
# define KEY_8 28
# define KEY_9 25
# define KEY_K 40
# define KEY_L 37
# define KEY_PLUS 24
# define KEY_MINUS 27
# define KEY_LESS 43
# define KEY_MORE 47

typedef struct s_line
{
	int		dx;
	int		sx;
	int		dy;
	int		sy;
	int		err;
	int		e2;
}			t_line;

typedef struct s_3d
{
	int		x;
	int		y;
	int		z;
	int		color;
}			t_3d;

typedef struct s_2d
{
	int		x;
	int		y;
	int		color;
}			t_2d;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_mouse
{
	int		x;
	int		y;
	int		is_pressed;
}			t_mouse;

typedef struct s_cam
{
	int		offset_x;
	int		offset_y;
	int		zoom;
	int		z_height;
	int		x_angle;
	int		y_angle;
	int		z_angle;
	int		iso;

}			t_cam;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	t_img	*img;
	int		height;
	int		width;
	t_cam	*cam;
	t_mouse	*mouse;
	t_2d	**coor_2d;
	t_3d	**coor_3d;
}			t_data;

// bresenham
void		plot(int x, int y, int color, t_data *data);
void		bresenhem_low(t_data *data, t_2d *p1, t_2d *p2);
void		bresenhem_high(t_data *data, t_2d *p1, t_2d *p2);
void		bresenhem(t_data *data, t_2d *a, t_2d *b);

// controls
int			mouse_down(int key, int x, int y, void *param);
int			mouse_up(int key, int x, int y, void *param);
int			mouse_move(int x, int y, void *param);
void		controls_hook(t_data *data);
int			key_press(int key, void *param);

// control_utils
int			on_destroy(void *param);
void		move_image(int key, t_data *data);
void		z_rotation(int key, t_data *data);
void		change_tallness(int key, t_data *data);

// gradient
int			get_color(int start, int end, int length, int current);

// main
t_cam		*cam_init(t_data *data);
t_mouse		*mouse_init(void);
void		data_init(t_data *data, char **av);
void		adjust_coor(t_data *data);

// mlx_stuff
void		my_mlx_pix_put(t_img *img, int x, int y, int color);
void		render_background(t_img *img, int color);
void		print_menu(t_data *data);
int			render(t_data *data);
void		plot_grid(t_data *data);

// parse
char		*read_file_fdf(char *filename);
char		***load_map(char *filename);
t_3d		**init_coor(char ***map);
void		str_to_coor(char *str, int i, int j, t_3d *res);
t_3d		**load_coor(char *filename, t_data *data);

// utils
int			ft_atoi_base(char *str, char *base);
void		ft_error(char *err);
void		free_all(t_data *data);
void		free_shit(char ***map);
int			check_valid_args(char *map);

// projection
void		rotate_z(int *x, int *y, int *z, double degree);
void		rotate_y(int *x, int *y, int *z, double degree);
void		rotate_x(int *x, int *y, int *z, double degree);
void		iso(int *x, int *y, int *z);
void		project(t_data *data);

// // extra?
// void		my_mlx_pix_put(t_img *img, int x, int y, int color);
// void		render_background(t_img *img, int color);
// void		plot_grid(t_data *data);
// int			render(t_data *data);
// void		data_init(t_data *data, char **av);
#endif
