/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_color_interpol.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:47:05 by smoroz            #+#    #+#             */
/*   Updated: 2024/01/16 11:55:30 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

static int	log_lerp_colors(int n, int c1, int c2, int max_iteration)
{
	int	c;

	if (n == 0)
		return (c1);
	c = (c2 - c1) / log(max_iteration) * log(n) + c1;
	return (c);
}

static int	log_lerp_trgb(int n, int c1, int c2, t_vars *vars)
{
	int	c1_trgb[4];
	int	c2_trgb[4];
	int	c[4];

	c1_trgb[1] = get_r(c1);
	c1_trgb[2] = get_g(c1);
	c1_trgb[3] = get_b(c1);
	c2_trgb[1] = get_r(c2);
	c2_trgb[2] = get_g(c2);
	c2_trgb[3] = get_b(c2);
	c[0] = 25;
	c[1] = log_lerp_colors(n, c1_trgb[1], c2_trgb[1], vars->max_iteration);
	c[2] = log_lerp_colors(n, c1_trgb[2], c2_trgb[2], vars->max_iteration);
	c[3] = log_lerp_colors(n, c1_trgb[3], c2_trgb[3], vars->max_iteration);
	return (create_trgb(c[0], c[1], c[2], c[3]));
}

int	color_manager(int n, t_vars *vars)
{
	int	color;

	if (vars->color_palette == C_GRAYSCALE)
		color = log_lerp_trgb(n, 0x000000, 0xffffff, vars);
	else if (vars->color_palette == C_BLUEGREEN)
		color = log_lerp_trgb(n, 0x00ff00, 0x0000ff, vars);
	else if (vars->color_palette == C_REDGREEN)
		color = log_lerp_trgb(n, 0xff0000, 0x00ff00, vars);
	else if (vars->color_palette == C_REDBLUE)
		color = log_lerp_trgb(n, 0xff0000, 0x0000ff, vars);
	else if (vars->color_palette == C_PASTEL_GREEN)
		color = log_lerp_trgb(n, 0xd6f8b8, 0x6b7b8e, vars);
	else
		color = log_lerp_colors(n, 0x000000, 0xffffff, vars->max_iteration);
	return (color);
}
