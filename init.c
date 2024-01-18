/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:48:16 by smoroz            #+#    #+#             */
/*   Updated: 2024/01/17 12:58:41 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}

static void	julia_set_init(t_vars *vars)
{
	vars->c[1].real = -0.022;
	vars->c[1].imag = 0.737348;
	vars->c[2].real = -0.7;
	vars->c[2].imag = 0.27015;
	vars->c[3].real = -0.79;
	vars->c[3].imag = 0.15;
	vars->c[5].real = -0.162;
	vars->c[5].imag = 1.04;
	vars->c[4].real = 0.3;
	vars->c[4].imag = -0.01;
	vars->c[8].real = 0.28;
	vars->c[8].imag = 0.008;
	vars->c[10].real = -0.12;
	vars->c[10].imag = -0.77;
	vars->c[7].real = -1.476;
	vars->c[7].imag = 0.0;
	vars->c[11].real = -0.785398;
	vars->c[11].imag = 1.1415 / 4.0;
	vars->c[6].real = -0.123;
	vars->c[6].imag = 0.745;
	vars->c[9].real = 0.285;
	vars->c[9].imag = 0.01;
}

static void	data_init(t_vars *vars)
{
	vars->color_palette = C_GRAYSCALE;
	vars->max_iteration = MAX_ITERATION;
	vars->world.zoom = 3.0;
	vars->world.move_x = 0.0;
	vars->world.move_y = 0.0;
	vars->c_idx = 0;
	julia_set_init(vars);
	vars->ri = 0;
	vars->need_update = 1;
}

static void	events_init(t_vars *vars)
{
	mlx_hook(vars->win, ON_KEYDOWN, 0, keys_hook, vars);
	mlx_hook(vars->win, ON_DESTROY, 0, destroy_window, vars);
	mlx_hook(vars->win, ON_MOUSEMOVE, 0, mouse_track_coord, vars);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
	mlx_loop_hook(vars->mlx, update, vars);
}

void	app_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		malloc_error("ERROR: 1");
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "Fractol");
	if (vars->win == NULL)
		malloc_error("ERROR: 2");
	vars->img.img_ptr = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (vars->img.img_ptr == NULL)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		malloc_error("ERROR: 3");
	}
	vars->img.img_pixels = mlx_get_data_addr(vars->img.img_ptr,
			&vars->img.bpp,
			&vars->img.line_length,
			&vars->img.endian);
	data_init(vars);
	events_init(vars);
}
