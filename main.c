/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:20:40 by smoroz            #+#    #+#             */
/*   Updated: 2024/01/17 13:01:55 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc == 2 || argc == 4)
	{
		ft_check_input(argc, argv, &vars);
		app_init(&vars);
		mlx_loop(vars.mlx);
	}
	else
	{
		ft_putstr_fd("Specify arguments:\n", 2);
		ft_error_fractal_type();
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

//	atexit(check_leaks2);
/*static void	check_leaks2(void)
{
	system("leaks fractol");
}
//*/
