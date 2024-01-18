/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:20:23 by smoroz            #+#    #+#             */
/*   Updated: 2024/01/17 12:11:39 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 512
# define HEIGHT 512
# define MAX_ITERATION 8
# define RSIZE 32

# define MANDELBROT 1
# define MANDELBROT4 2
# define BURNINGSHIP 3
# define JULIA 4

# define M_LMB 1
# define M_RMB 2
# define M_MMB 3
# define M_SCROLL_DOWN 4
# define M_SCROLL_UP 5

# define C_GRAYSCALE 1
# define C_BLUEGREEN 2
# define C_REDGREEN 3
# define C_REDBLUE 4
# define C_PASTEL_GREEN 5
# define C_SIMPLE 6

# include "minilibx/mlx.h"
# include "minilibx_keys.h"
# include "minilibx_events.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_int_point
{
	int	x;
	int	y;
}		t_int_point;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels;
	int		bpp;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_world
{
	double	move_x;
	double	move_y;
	double	zoom;
}			t_world;

typedef struct s_complex
{
	double	real;
	double	imag;
}			t_complex;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_world		world;
	int			type;
	t_complex	c[12];
	int			c_idx;
	int			cur_iteration;
	int			max_iteration;
	int			color_palette;
	int			need_update;
	int			ri;
}				t_vars;

//	init.c
void		app_init(t_vars *vars);

//	fractals.c
int			ft_julia(t_complex z, t_complex c, int max_iteration);
int			ft_burning_ship(t_complex z, int max_iteration);
int			ft_mandelbrot(t_complex c, int max_iteration);
int			ft_mandelbrot_4(t_complex c, int max_iteration);

// colors.c
int			create_trgb(int t, int r, int g, int b);
int			get_t(int trgb);
int			get_r(int trgb);
int			get_g(int trgb);
int			get_b(int trgb);

//	utils_color_interpol.c
int			color_manager(int n, t_vars *vars);

//	render.c
int			iteration_at_pixel(int x, int y, t_vars *vars);
void		render_h(t_vars *vars);

//	hooks.c
int			destroy_window(t_vars *vars);
int			keys_hook(int keycode, t_vars *vars);
int			mouse_hook(int event, int x, int y, t_vars *vars);
int			mouse_track_coord(int x, int y, t_vars *vars);

//	ft_atof.c
double		ft_atof(char *s);

//	ft_isvalid_int.c
int			ft_isvalid_int(const char *str);

//	ft_isvalid_float.c
int			ft_isvalid_float(const char *str);

//	utils_check_input.c
void		ft_check_input(int argc, char **argv, t_vars *vars);

//	utils_errors.c
void		ft_error_fractal_type(void);
void		ft_error_julia1(void);
void		ft_error_julia2(void);

//	utils_math.c
int			ft_min(int a, int b);
int			ft_max(int a, int b);

//	utils_math_complex.c
t_complex	screen2coord(int x, int y, t_vars *vars);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
double		abs_complex(t_complex z);

//	utils_hooks_1.c
void		inc_view_iteration(t_vars *vars);
void		dec_view_iteration(t_vars *vars);
void		change_color_palette(t_vars *vars);
void		change_fractal_type(int keycode, t_vars *vars);
void		change_julia_set(int keycode, t_vars *vars);

//	utils_hooks_2.c
void		translate_view(int dx, int dy, t_vars *vars);
void		reset_view(t_vars *vars);
int			update(t_vars *vars);

//	utils_hilbert_curve.c
t_int_point	hindex2xy(int hindex, int order);

#endif
