/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hilbert_curve.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:57:49 by smoroz            #+#    #+#             */
/*   Updated: 2024/01/16 11:57:30 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_int_point	point_add_xy(t_int_point point, int dx, int dy)
{
	point.x += dx;
	point.y += dy;
	return (point);
}

static t_int_point	point_swap_xy(t_int_point point)
{
	int	tmp;

	tmp = point.x;
	point.x = point.y;
	point.y = tmp;
	return (point);
}

static t_int_point	hindex2xy_n2(int hindex)
{
	t_int_point	positions[4];

	positions[0].x = 0;
	positions[0].y = 0;
	positions[1].x = 0;
	positions[1].y = 1;
	positions[2].x = 1;
	positions[2].y = 1;
	positions[3].x = 1;
	positions[3].y = 0;
	return (positions[hindex]);
}

static int	last2bits(int x)
{
	return (x & 3);
}

t_int_point	hindex2xy(int hindex, int order)
{
	t_int_point	point;
	int			n;
	int			t;

	point = hindex2xy_n2(last2bits(hindex));
	n = 4;
	while (n <= order)
	{
		hindex = hindex >> 2;
		if (last2bits(hindex) == 0)
			point = point_swap_xy(point);
		else if (last2bits(hindex) == 1)
			point.y += n / 2;
		else if (last2bits(hindex) == 2)
			point = point_add_xy(point, n / 2, n / 2);
		else if (last2bits(hindex) == 3)
		{
			t = point.y;
			point.y = (n / 2 - 1) - point.x;
			point.x = n - 1 - t;
		}
		n *= 2;
	}
	return (point);
}
