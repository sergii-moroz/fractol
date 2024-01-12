/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_color_interpol.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:47:05 by smoroz            #+#    #+#             */
/*   Updated: 2024/01/12 11:56:48 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

/*int	lerp_colors(int n, int c1, int c2, int max_iteration)
{
	return ((c2 - c1) / max_iteration * n + c1);
}*/

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

/*int	log_grayscale(int n, int max_iteration)
{
	int c;

	if (n == 0)
		return (0);
	c = 255 / log(max_iteration) * log(n);
	return (create_trgb(c, c, c, c));
}*/

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
	else if (vars->color_palette == C_SIMPLE)
		color = log_lerp_colors(n, 0x000000, 0xffffff, vars->max_iteration);
	return (color);
}

/*void	rgb2hsv(double r, double g, double b)
{
	double	cmax;
	double	cmin;
	double	h;
	double	s;
	double	v;

	r /= 255.0;
	g /= 255.0;
	b /= 255.0;
	cmax = fmax(r, fmax(g, b));
	cmin = fmin(r, fmin(g, b));
	v = cmax;
	if (cmax == 0)
		s = 0;
	else
		s = ((cmax - cmin) / cmax);
	if (cmax == cmin)
		h = 0;
	else if (cmax == r)
		h = 60.0 * fmod((g - b) / (cmax - cmin), 6);
	else if (cmax == g)
		h = 60.0 * ((b - r) / (cmax - cmin) + 2.0);
	else
		h = 60.0 * ((r - g) / (cmax - cmin) + 4.0);
	printf("RGB: %f, %f, %f, HSV: %f, %f, %f\n", r, g, b, h, s, v);
}*/

/*int	hsv2rgb(int hr, int sg, int vb)
{
	double	c;
	double	x;
	double	m;

	c = vb * sg;
	x = c * (1.0 - fabs(fmod(hr / 60.0, 2.0) - 1.0));
	m = vb - c;
	if (hr >= 0.0 && hr < 60.0)
	{
		hr = c; sg = x; vb = 0;
	}
	else if ( hr >= 60.0 && hr < 120.0)
	{
		hr = x; sg = c; vb = 0;
	}
	else if (hr >= 120.0 && hr < 180.0)
	{
		hr = 0; sg = c; vb = x;
	}
	else if (hr >= 180.0 && hr < 240.0)
	{
		hr = 0; sg = x; vb = c;
	}
	else if (hr >= 240.0 && hr < 300.0)
	{
		hr = x; sg = 0; vb = c;
	}
	else if (hr >= 300.0 && hr < 360.0)
	{
		hr = c; sg = 0; vb = x;
	}
	hr = 255.0 * (hr + m);
	sg = 255.0 * (sg + m);
	vb = 255.0 * (vb + m);
	//printf("RGB: %d, %d, %d\n", (int)hr, (int)sg, (int)vb);
	return create_trgb(0, hr, sg, vb);
}*/
