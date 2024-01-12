/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:20:23 by smoroz            #+#    #+#             */
/*   Updated: 2024/01/12 11:21:18 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1920/2
# define HEIGHT 1080/2
# define MAX_ITERATION 8

# define MANDELBROT 1
# define MANDELBROT4 2
# define BURNINGSHIP 3
# define JULIA 4

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_R 15
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
# define KEY_4 21
# define KEY_5 23
# define KEY_6 22
# define KEY_7 26
# define KEY_8 28
# define KEY_9 25
# define KEY_0 29
# define KEY_SPACE 49
# define KEY_ESC 53
# define KEY_PLUS 69
# define KEY_MINUS 78
# define KEY_NUM_1 83
# define KEY_NUM_2 84
# define KEY_NUM_3 85
# define KEY_NUM_4 86
# define KEY_PAGEUP 116
# define KEY_PAGEDOWN 121
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

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
	double	moveX;
	double	moveY;
	double	zoom;
}			t_world;

typedef struct	s_complex
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
//	int			n_iter;
	int			color_palette;
}				t_vars;

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h> // TODO

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
int			hsv2rgb(int hr, int sg, int vb);
//void		rgb2hsv(double r, double g, double b);
//int			lerp_colors(int n, int c1, int c2, int max_iteration);
//int			log_lerp_colors(int n, int c1, int c2, int max_iteration);
//int			log_grayscale(int n, int max_iteration);

//	render.c
void		render(t_vars *vars);
int			iteration_at_pixel(int x, int y, t_vars *vars);

//	hooks.c
int			destroy_window(t_vars *vars);
int			keys_hook(int keycode, t_vars *vars);
int			mouse_hook(int event, int x, int y, t_vars *vars);

//	ft_atof.c
double		ft_atof(char *s);

//	ft_isvalid_int.c
int		ft_isvalid_int(const char *str);

//	ft_isvalid_float.c
int		ft_isvalid_float(const char *str);

//	utils_check_input.c
void	ft_check_input(int argc, char **argv, t_vars *vars);

//	utils_errors.c
void	ft_error_fractal_type(void);
void	ft_error_julia1(void);
void	ft_error_julia2(void);

//	utils_math.c
int			ft_min(int a, int b);
int			ft_max(int a, int b);

//	utils_math_complex.c
t_complex	screen2coord(int x, int y, t_vars *vars);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
double		abs_complex(t_complex z);
//t_complex	mult_complex(t_complex a, t_complex b);
//t_complex	create_z(double real, double imag);
//t_complex	div_complex(t_complex a, t_complex b);

//	utils_settings.c
void	inc_view_iteration(t_vars *vars);
void	dec_view_iteration(t_vars *vars);
void	change_color_palette(t_vars *vars);

#endif
