/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:48:28 by smoroz            #+#    #+#             */
/*   Updated: 2024/01/12 12:30:40 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
//void check_leaks();
int	destroy_window(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img_ptr);
	mlx_destroy_window(vars->mlx, vars->win);
//	check_leaks();
	exit(EXIT_SUCCESS);
}

static void	reset_view(t_vars *vars)
{
	vars->world.zoom = 3.0;
	vars->world.moveX = 0.0;
	vars->world.moveY = 0.0;
	vars->max_iteration = MAX_ITERATION;
//	vars->n_iter = 3;
}

int	keys_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		destroy_window(vars);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		vars->world.moveX += 0.1 * vars->world.zoom;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		vars->world.moveX -= 0.1 * vars->world.zoom;
	else if (keycode == KEY_W || keycode == KEY_UP)
		vars->world.moveY -= 0.1 * vars->world.zoom;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		vars->world.moveY += 0.1 * vars->world.zoom;
	else if (keycode == KEY_PLUS || keycode == KEY_PAGEUP)
		inc_view_iteration(vars);
	else if (keycode == KEY_MINUS || keycode == KEY_PAGEDOWN)
		dec_view_iteration(vars);
	else if (keycode == KEY_R)
		reset_view(vars);
	else if (keycode == KEY_SPACE)
		change_color_palette(vars);
	else if (keycode >= KEY_NUM_1 && keycode <= KEY_NUM_4)
		vars->type = keycode - 82;
	else if (keycode >= KEY_1 && keycode <= KEY_0)
		vars->c_idx = keycode - KEY_1;
	render(vars);
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
		vars->world.moveX += z_new.real - z.real;
		vars->world.moveY += z_new.imag - z.imag;
	}
	else if (event == M_SCROLL_DOWN)
	{
		vars->world.zoom *= 0.95;
		z_new = screen2coord(x, y, vars);
		vars->world.moveX -= z_new.real - z.real;
		vars->world.moveY -= z_new.imag - z.imag;
	}
	render(vars);
	if (event == M_LMB)
		show_iter_label(x, y, vars);
	return (0);
}
