/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hooks_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:35:49 by smoroz            #+#    #+#             */
/*   Updated: 2024/01/15 20:40:15 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	inc_view_iteration(t_vars *vars)
{
	if (vars->max_iteration < 2048)
	{
		vars->max_iteration *= 2;
		vars->ri = 0;
		vars->need_update = 1;
	}
}

void	dec_view_iteration(t_vars *vars)
{
	if (vars->max_iteration >= 16)
	{
		vars->max_iteration /= 2;
		vars->ri = 0;
		vars->need_update = 1;
	}
}

void	change_color_palette(t_vars *vars)
{
	if (vars->color_palette == C_SIMPLE)
		vars->color_palette = C_GRAYSCALE;
	else
		vars->color_palette += 1;
	vars->ri = 0;
	vars->need_update = 1;
}

void	change_fractal_type(int keycode, t_vars *vars)
{
	vars->type = keycode - 82;
	vars->ri = 0;
	vars->need_update = 1;
}

void	change_julia_set(int keycode, t_vars *vars)
{
	vars->c_idx = keycode - KEY_1;
	vars->ri = 0;
	vars->need_update = 1;
}
