/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:40:27 by smoroz            #+#    #+#             */
/*   Updated: 2024/01/16 12:11:29 by smoroz           ###   ########.fr       */
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

	n = 0;
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

	n = 0;
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
	ft_pixel_put(&vars->img, x, y, color);
}

static void	handle_rect(int x, int y, t_vars *vars)
{
	int	dx;
	int	dy;

	dy = 0;
	while (dy < RSIZE)
	{
		dx = 0;
		while (dx < RSIZE)
		{
			handle_pixel(x + dx, y - dy, vars);
			dx++;
		}
		dy++;
	}
}

void	render_h(t_vars *vars)
{
	int			order;
	t_int_point	point;

	mlx_clear_window(vars->mlx, vars->win);
	order = WIDTH / RSIZE;
	point = hindex2xy(vars->ri, order);
	point.y = -(point.y * RSIZE) + HEIGHT - 1;
	point.x = point.x * RSIZE;
	vars->cur_iteration = 2;
	while (vars->cur_iteration <= vars->max_iteration)
	{
		handle_rect(point.x, point.y, vars);
		vars->cur_iteration *= 2;
	}
	if (vars->ri < order * order)
		vars->ri++;
	else
	{
		vars->ri = 0;
		vars->need_update = 0;
	}
}
