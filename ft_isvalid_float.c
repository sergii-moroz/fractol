/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:33:15 by smoroz            #+#    #+#             */
/*   Updated: 2024/01/11 20:33:48 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_isvalid_ipart(const char *str)
{
	if (ft_strlen(str) == 0)
		return (0);
	while (ft_isspace(*str))
		str++;
	if (*str == '\0')
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (0);
	while (ft_isdigit(*str))
		str++;
	if (*str == '\0' || *str == '.')
		return (1);
	return (0);
}

static int	ft_isvalid_fpart(const char *str)
{
	if (ft_strlen(str) == 0)
		return (0);
	str = ft_strchr(str, '.');
	if (str == NULL)
		return (1);
	str++;
	if (*str == '\0' || ft_isvalid_int(str))
		return (1);
	return (0);
}

int	ft_isvalid_float(const char *str)
{
	if (!ft_isvalid_ipart(str) || !ft_isvalid_fpart(str))
		return (0);
	return (1);
}
