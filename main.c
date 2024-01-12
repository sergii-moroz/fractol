/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:20:40 by smoroz            #+#    #+#             */
/*   Updated: 2024/01/12 12:25:08 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void	check_leaks2(void)
{
	system("leaks fractol");
}

int	main(int argc, char **argv)
{
	t_vars	vars;

//	atexit(check_leaks2);

	if (argc == 2 || argc == 4)
	{
		ft_check_input(argc, argv, &vars);
		app_init(&vars);
		render(&vars);
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
	//system("leaks fractol"); //leak check

/*void	ft_pixel_put(t_img *img, t_point *point)
{
	char	*dst;
	int		offset;

	offset = point->y * img->line_length + point->x * (img->bpp / 8);
	dst = img->img_pixels + offset;
	*(unsigned *)dst = point->color;
}*/

/*void	ft_hline_put(t_img *img, t_point point, int width)
{
	int	end;

	end = point.x + width;
	while (point.x < end)
	{
		ft_pixel_put(img, &point);
		point.x++;
	}
}

void	ft_rect_put(t_img *img, t_point p1, t_point p2)
{
	int	width;

	width = p2.x - p1.x;
	while (p1.y < p2.y)
	{
		ft_hline_put(img, p1, width);
		p1.y++;
	}
}*/

/*int	main(void)
{
	t_vars	vars;
	//t_point	point;
	//t_point	point2;
	//t_complex c;

	vars.world.zoom = 1.0;
	vars.world.moveX = 0;
	vars.world.moveY = 0;
	vars.c.real = -0.7;
	vars.c.imaginary = 0.27015;
	vars.max_iteration = MAX_ITERATION;
	//app_init(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Fractol by smoroz");
	vars.img.img_ptr = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.img.img_pixels = mlx_get_data_addr(vars.img.img_ptr,
								&vars.img.bpp,
								&vars.img.line_length,
								&vars.img.endian);
	//point.x = 5;
	//point.y = 5;
	//point.color = 0xff0000;
	//point2.x = 25;
	//point2.y = 50;
	//point.color = 0xff0000;
	//ft_pixel_put(&img, &point);
	//ft_hline_put(&img, point, 50);
	//ft_rect_put(&img, point, point2);

	ft_julia2img(&vars.img, &vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img_ptr, 0, 0);
	//rgb2hsv(255, 255, 0);
	// hsv2rgb(180, 1, 1);
	mlx_hook(vars.win, 2, 0, &keys_hook, &vars);
	mlx_hook(vars.win, 17, 0, &destroy_window, &vars);
	mlx_mouse_hook(vars.win, &mouse_hook, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_image(vars.mlx, vars.img.img_ptr);
	mlx_destroy_window(vars.mlx, vars.win);
	return (0);
}*/
