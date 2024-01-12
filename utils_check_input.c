/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:00:02 by smoroz            #+#    #+#             */
/*   Updated: 2024/01/11 20:34:52 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_check_input(int argc, char **argv, t_vars *vars)
{
	long	n;

	if (argc >= 2)
	{
		if (!ft_isvalid_int(argv[1]))
			ft_error_fractal_type();
		n = ft_atoi(argv[1]);
		if (n < MANDELBROT || n > JULIA)
			ft_error_fractal_type();
		vars->type = (int)n;
		if (vars->type == JULIA && argc == 2)
			ft_error_julia1();
	}
	if (argc == 4)
	{
		if (!ft_isvalid_float(argv[2]) || !ft_isvalid_float(argv[3]))
			ft_error_julia2();
		vars->c[0].real = ft_atof(argv[2]);
		vars->c[0].imag = ft_atof(argv[3]);
	}
}
