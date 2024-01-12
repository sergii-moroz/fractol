/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:47:12 by smoroz            #+#    #+#             */
/*   Updated: 2024/01/11 19:50:17 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

int	ft_mandelbrot(t_complex c, int max_iteration)
{
	int			i;
	t_complex	z;

	z.real = 0.0;
	z.imag = 0.0;
	i = 0;
	while (i < max_iteration)
	{
		z = sum_complex(square_complex(z), c);
		if (abs_complex(z) > 4.0)
			return (i);
		i++;
	}
	return (i);
}

int	ft_mandelbrot_4(t_complex c, int max_iteration)
{
	int			i;
	t_complex	z;

	z.real = 0.0;
	z.imag = 0.0;
	i = 0;
	while (i < max_iteration)
	{
		z = sum_complex(square_complex(square_complex(z)), c);
		if (abs_complex(z) > 4.0)
			return (i);
		i++;
	}
	return (i);
}

int	ft_julia(t_complex z, t_complex c, int max_iteration)
{
	int			i;
	t_complex	z_new;

	i = 0;
	while (i < max_iteration)
	{
		z_new.real = z.real * z.real - z.imag * z.imag + c.real;
		z_new.imag = 2.0 * z.real * z.imag + c.imag;
		if (z_new.real * z_new.real + z_new.imag * z_new.imag > 4.0)
			return (i);
		z.real = z_new.real;
		z.imag = z_new.imag;
		i++;
	}
	return (i);
}

int	ft_burning_ship(t_complex z, int max_iteration)
{
	int			i;
	t_complex	z_new;
	t_complex	c;

	c.real = z.real;
	c.imag = z.imag;
	i = 0;
	while (i < max_iteration)
	{
		z_new.real = z.real * z.real - z.imag * z.imag + c.real;
		z_new.imag = fabs(2.0 * z.real * z.imag) + c.imag;
		if (z_new.real * z_new.real + z_new.imag * z_new.imag > 4.0)
			return (i);
		z.real = z_new.real;
		z.imag = z_new.imag;
		i++;
	}
	return (i);
}
