/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:33:15 by smoroz            #+#    #+#             */
/*   Updated: 2024/01/17 13:57:55 by smoroz           ###   ########.fr       */
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

static int	ft_ipart_isempty(const char *str)
{
	int	count;

	count = 0;
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
	{
		str++;
		count++;
	}
	if (*str == '\0' || *str == '.')
		return (count);
	return (0);
}

static int	ft_isvalid_fpart(const char *str)
{
	const char	*str0;

	str0 = str;
	if (ft_strlen(str) == 0)
		return (0);
	str = ft_strchr(str, '.');
	if (str == NULL)
		return (1);
	str++;
	if ((*str == '\0' && ft_ipart_isempty(str0) > 0) || ft_isvalid_int(str))
		return (1);
	return (0);
}

int	ft_isvalid_float(const char *str)
{
	if (!ft_isvalid_ipart(str) || !ft_isvalid_fpart(str))
		return (0);
	return (1);
}
