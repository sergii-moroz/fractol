/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:43:53 by smoroz            #+#    #+#             */
/*   Updated: 2024/01/12 21:58:36 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	ft_fract(char *s)
{
	double	fract;
	double	pow;

	fract = 0.0;
	s = ft_strchr(s, '.');
	if (s == NULL)
		return (fract);
	s++;
	pow = 1.0;
	while (*s >= '0' && *s <= '9')
	{
		pow /= 10.0;
		fract = fract + (*s - '0') * pow;
		s++;
	}
	return (fract);
}

double	ft_atof(char *s)
{
	double	frac_part;
	long	int_part;
	int		sign;

	int_part = 0;
	frac_part = 0.0;
	sign = 1;
	while (ft_isspace(*s))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		int_part = int_part * 10 + *s - '0';
		s++;
	}
	frac_part = ft_fract(s);
	return (sign * (int_part + frac_part));
}
