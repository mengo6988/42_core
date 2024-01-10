/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mho <mho@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 08:05:20 by mho               #+#    #+#             */
/*   Updated: 2024/01/10 16:25:23 by mho              ###   ########.fr       */
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
# define BASE "0123456789abcdef"

typedef struct s_line
{
	int			dx;
	int			sx;
	int			dy;
	int			sy;
	int			err;
	int			e2;
}				t_line;

typedef struct s_rect
{
	int			x;
	int			y;
	int			width;
	int			height;
	int			color;
}				t_rect;

typedef struct s_mat
{
	int			**mat;
	int			rows;
	int			cols;
}				t_mat;

typedef struct s_3d
{
	int			x;
	int			y;
	int			z;
	uint32_t	color;
}				t_3d;

typedef struct s_2d
{
	int			x;
	int			y;
	uint32_t	color;
}				t_2d;

typedef struct s_img
{
	void		*mlx_img;
	char		*addr;
	int			bits_per_pixel;
	int			line_len;
	int			endian;
}				t_img;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	t_img		*img;
	int			offset_x;
	int			offset_y;
	int			height;
	int			width;
	t_2d		**coor_2d;
	t_3d		**coor_3d;
}				t_data;

void			bresenhem(t_data *data, t_2d *a, t_2d *b);
void			bresenhem_high(t_data *data, t_2d *p1, t_2d *p2);
void			bresenhem_low(t_data *data, t_2d *p1, t_2d *p2);
void			plot(int x, int y, t_data *data);
// void	bs(t_data *data, t_2d *a, t_2d *b);
// t_line *init_line(t_2d *a, t_2d *b);
// int compare(int a, int b);
// void bresenham(t_data *data, t_2d *p1, t_2d *p2);
// void	draw_line(t_data *fdf, t_2d *f, t_2d *s );

int				check_valid_args(char *map);
char			*read_file_fdf(char *filename);
char			***load_map(char *filename);
t_3d			**init_coor(char ***map);
void			str_to_coor(char *str, int i, int j, t_3d *res);
void			free_shit(char ***map);
t_3d			**load_coor(char *filename, t_data *data);

// void			my_mlx_pix_put(t_img *img, int x, int y, int color);
int				mouse_event(int keycode, int x, int y, t_data *param);

//utils
void			ft_error(char *err);
uint32_t	ft_atoi_base(char *str, char *base);

//projection
void			iso(t_data *data);

// extra?
int handle_keypress(int keysym, t_data *data);
void my_mlx_pix_put(t_img *img, int x, int y, int color);
void render_background(t_img *img, int color);
int render_rect(t_img *img, t_rect rect);
void	plot_grid(t_data *data);
int key_hook(int keycode, t_data *data);
int render(t_data *data);
void data_init(t_data *data, char **av);
#endif
