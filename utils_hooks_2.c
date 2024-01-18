/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hooks_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:39:13 by smoroz            #+#    #+#             */
/*   Updated: 2024/01/16 12:11:16 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	translate_view(int dx, int dy, t_vars *vars)
{
	vars->world.move_x += dx * 0.1 * vars->world.zoom;
	vars->world.move_y += dy * 0.1 * vars->world.zoom;
	vars->ri = 0;
	vars->need_update = 1;
}

static void	legend_show(t_vars *vars)
{
	char	*s1;
	char	*s2;

	s1 = ft_itoa(vars->max_iteration);
	s2 = ft_strjoin("max iter: ", s1);
	mlx_string_put(vars->mlx, vars->win, WIDTH * 0.05, \
		HEIGHT * 0.95, 0xff00ff, s2);
	free(s1);
	free(s2);
}

void	reset_view(t_vars *vars)
{
	vars->world.zoom = 3.0;
	vars->world.move_x = 0.0;
	vars->world.move_y = 0.0;
	vars->max_iteration = MAX_ITERATION;
	vars->ri = 0;
	vars->need_update = 1;
}

int	update(t_vars *vars)
{
	if (vars->need_update)
	{
		render_h(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_ptr, 0, 0);
		legend_show(vars);
	}
	return (0);
}
