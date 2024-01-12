/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:35:49 by smoroz            #+#    #+#             */
/*   Updated: 2024/01/12 11:23:35 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	inc_view_iteration(t_vars *vars)
{
	if (vars->max_iteration < 1024)
	{
		vars->max_iteration *= 2;
//		vars->n_iter += 1;
	}
}

void	dec_view_iteration(t_vars *vars)
{
	if (vars->max_iteration >= 16)
	{
		vars->max_iteration /= 2;
//		vars->n_iter -= 1;
	}
}

void	change_color_palette(t_vars *vars)
{
	if (vars->color_palette == C_SIMPLE)
		vars->color_palette = C_GRAYSCALE;
	else
		vars->color_palette += 1;
}
