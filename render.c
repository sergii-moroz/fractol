/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:40:27 by smoroz            #+#    #+#             */
/*   Updated: 2024/01/12 12:00:20 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = y * img->line_length + x * (img->bpp / 8);
	dst = img->img_pixels + offset;
	*(unsigned *)dst = color;
}

int	iteration_at_pixel(int x, int y, t_vars *vars)
{
	t_complex	c;
	int			n;

	c = screen2coord(x, y, vars);
	if (vars->type == MANDELBROT)
		n = ft_mandelbrot(c, vars->max_iteration);
	else if (vars->type == MANDELBROT4)
		n = ft_mandelbrot_4(c, vars->max_iteration);
	else if (vars->type == BURNINGSHIP)
		n = ft_burning_ship(c, vars->max_iteration);
	else if (vars->type == JULIA)
		n = ft_julia(c, vars->c[vars->c_idx], vars->max_iteration);
	return (n);
}

static void	handle_pixel(int x, int y, t_vars *vars)
{
	t_complex	c;
	int			n;
	int			color;

	c = screen2coord(x, y, vars);
	if (vars->type == MANDELBROT)
		n = ft_mandelbrot(c, vars->cur_iteration);
	else if (vars->type == MANDELBROT4)
		n = ft_mandelbrot_4(c, vars->cur_iteration);
	else if (vars->type == BURNINGSHIP)
		n = ft_burning_ship(c, vars->cur_iteration);
	else if (vars->type == JULIA)
		n = ft_julia(c, vars->c[vars->c_idx], vars->cur_iteration);
	color = color_manager(n, vars);
	//color = hsv2rgb(n % 360, 1, n < vars->max_iteration);
	ft_pixel_put(&vars->img, x, y, color);
}

static void	handel_image(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, vars);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_ptr, 0, 0);
}

void	render(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	vars->cur_iteration = 2;
	while (vars->cur_iteration <= vars->max_iteration)
	{
		handel_image(vars);
		vars->cur_iteration *= 2;
	}
	char	*s1;
	char	*s2;
	s1 = ft_itoa(vars->max_iteration);
	s2 = ft_strjoin("max iter: ", s1);
	mlx_string_put(vars->mlx, vars->win, WIDTH * 0.05, \
		HEIGHT * 0.95, 0xff00ff, s2);
	free(s1);
	free(s2);
}

/*
int	x;
int	y;

y = 0;
while (y < HEIGHT)
{
	x = 0;
	while (x < WIDTH)
	{
		handle_pixel(x, y, vars);
		x++;
	}
	y++;
}
mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_ptr, 0, 0);
//mlx_string_put(vars->mlx, vars->win, WIDTH * 0.05, \
	HEIGHT * 0.95, 0xff00ff, "Fractal");
*/
