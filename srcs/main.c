/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:28:53 by anleclab          #+#    #+#             */
/*   Updated: 2019/02/18 11:16:58 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	usage(void)
{
	ft_putstr("usage: ./fractol fractal_name\n");
	ft_putstr("Available fractals: [mandelbrot/man] [julia/jul]\n");
}

static void	error(char *str, t_fract *fract)
{
	ft_putstr_fd("error :", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	end(fract, EXIT_ERROR);
}

static void	fract_init(t_fract *fract)
{
	fract->addr = NULL;
	fract->mlx_ptr = NULL;
	fract->win_ptr = NULL;
	fract->img_ptr = NULL;
}

int			main(int ac, char **av)
{
	t_fract	fract;

	if (ac != 2 || (fract.name = which_fractal(av[1])) == NONE)
	{
		usage();
		exit(0);
	}
	fract_init(&fract);
	if (!(fract.mlx_ptr = mlx_init()))
		error("failed to initialize mlx connection", &fract);
	if (!(fract.win_ptr = mlx_new_window(fract.mlx_ptr, WIDTH, HEIGHT,
											av[1])))
		error("mlx failure", &fract);
	if (!new_image(&fract))
		error("filed to create image", &fract);
	draw_fractal(&fract);
	mlx_hook(fract.win_ptr, 17, 0, &close_win, &fract);
	mlx_hook(fract.win_ptr, 3, 0, &key_release, &fract);
	mlx_loop(fract.mlx_ptr);
}
