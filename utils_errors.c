/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:12:43 by smoroz            #+#    #+#             */
/*   Updated: 2024/01/11 19:13:55 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error_fractal_type(void)
{
	ft_putstr_fd("ERROR:\tfractal type should be integer between [1 - 4]\n", 2);
	ft_putstr_fd("\t1 - Mandelbrot\n\t2 - Mandelbrot 4\n", 2);
	ft_putstr_fd("\t3 - Burning ship\n", 2);
	ft_putstr_fd("\t4 - Julia <float> <float>\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_error_julia1(void)
{
	ft_putstr_fd("ERROR: ", 2);
	ft_putstr_fd("\ttoo few parameter for fractal \"Julia\" (type 2)\n", 2);
	ft_putstr_fd("\tspecify two arguments of type double ", 2);
	ft_putstr_fd("<real> <imaginary>\n", 2);
	ft_putstr_fd("\n\tEXAMPLE:\n\t./fractol 2 -0.6 0.6\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_error_julia2(void)
{
	ft_putstr_fd("ERROR: ", 2);
	ft_putstr_fd("2nd or 3rd argument isn't valid double\n", 2);
	ft_putstr_fd("\n\tEXAMPLE:\n\t./fractol 2 -0.6 0.6\n", 2);
	exit(EXIT_FAILURE);
}
