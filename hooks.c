/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:48:28 by smoroz            #+#    #+#             */
/*   Updated: 2024/01/17 12:57:35 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	destroy_window(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img_ptr);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(EXIT_SUCCESS);
}

int	keys_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		destroy_window(vars);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		translate_view(1, 0, vars);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		translate_view(-1, 0, vars);
	else if (keycode == KEY_W || keycode == KEY_UP)
		translate_view(0, -1, vars);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		translate_view(0, 1, vars);
	else if (keycode == KEY_PLUS || keycode == KEY_PAGEUP)
		inc_view_iteration(vars);
	else if (keycode == KEY_MINUS || keycode == KEY_PAGEDOWN)
		dec_view_iteration(vars);
	else if (keycode == KEY_R)
		reset_view(vars);
	else if (keycode == KEY_SPACE)
		change_color_palette(vars);
	else if (keycode >= KEY_NUM_1 && keycode <= KEY_NUM_4)
		change_fractal_type(keycode, vars);
	else if (keycode >= KEY_1 && keycode <= KEY_0)
		change_julia_set(keycode, vars);
	return (0);
}

static void	show_iter_label(int x, int y, t_vars *vars)
{
	char	*s;

	s = ft_itoa(iteration_at_pixel(x, y, vars));
	mlx_string_put(vars->mlx, vars->win, x, y, 0xff00ff, s);
	free(s);
}

int	mouse_hook(int event, int x, int y, t_vars *vars)
{
	t_complex	z;
	t_complex	z_new;

	z = screen2coord(x, y, vars);
	if (event == M_SCROLL_UP)
	{
		vars->world.zoom *= 1.05;
		z_new = screen2coord(x, y, vars);
		vars->world.move_x -= z_new.real - z.real;
		vars->world.move_y -= z_new.imag - z.imag;
		vars->ri = 0;
		vars->need_update = 1;
	}
	else if (event == M_SCROLL_DOWN)
	{
		vars->world.zoom *= 0.95;
		z_new = screen2coord(x, y, vars);
		vars->world.move_x -= z_new.real - z.real;
		vars->world.move_y -= z_new.imag - z.imag;
		vars->ri = 0;
		vars->need_update = 1;
	}
	if (event == M_LMB)
		show_iter_label(x, y, vars);
	return (0);
}

int	mouse_track_coord(int x, int y, t_vars *vars)
{
	t_complex	z;

	if (vars->type == JULIA && vars->c_idx == 6)
	{
		z = screen2coord(x, y, vars);
		vars->c[6] = z;
		vars->ri = 0;
		vars->need_update = 1;
	}
	return (0);
}
