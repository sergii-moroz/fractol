/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_complex_math.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:05:10 by smoroz            #+#    #+#             */
/*   Updated: 2024/01/11 20:24:47 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	screen2coord(int x, int y, t_vars *vars)
{
	t_complex	z;
	int			min_screen;

	min_screen = ft_min(WIDTH, HEIGHT);
	z.real = (x - 0.5 * WIDTH) * vars->world.zoom / min_screen \
		+ vars->world.moveX;
	z.imag = (-y + 0.5 * HEIGHT) * vars->world.zoom / min_screen \
		+ vars->world.moveY;
	return (z);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.real = z1.real + z2.real;
	res.imag = z1.imag + z2.imag;
	return (res);
}

t_complex	square_complex(t_complex z)
{
	t_complex	res;

	res.real = z.real * z.real - z.imag * z.imag;
	res.imag = 2.0 * z.real * z.imag;
	return (res);
}

double	abs_complex(t_complex z)
{
	return (z.real * z.real + z.imag * z.imag);
}

/*t_complex	mult_complex(t_complex a, t_complex b)
{
	t_complex	res;

	res.real = a.real * b.real - a.imag * b.imag;
	res.imag = a.real * b.imag + a.imag * b.real;
	return (res);
}

t_complex	create_z(double real, double imag)
{
	t_complex	z;

	z.real = real;
	z.imag = imag;
	return (z);
}

t_complex	div_complex(t_complex a, t_complex b)
{
	t_complex	res;
	double		ab;

	ab = b.real * b.real + b.imag * b.imag;
	res.real = (a.real * b.real + a.imag * b.imag) / ab;
	res.imag = (-a.real * b.imag + b.real * a.imag) / ab;
	return (res);
}*/
