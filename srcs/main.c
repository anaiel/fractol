/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:28:53 by anleclab          #+#    #+#             */
/*   Updated: 2019/02/15 16:43:19 by anleclab         ###   ########.fr       */
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

int		main(int ac, char **av)
{
	t_fract	fract;

	if (ac != 2 || !(fract.name = which_fractal(av[1])))
	{
		usage();
		exit(0);
	}
	if (!(fract.mlx_ptr = mlx_init()))
		error("failed to initialize mlx connection", &fract);
	if (!(fract.win_ptr = mlx_new_window(fract.mlx_ptr, HEIGHT, WIDTH,
											av[1])))
		error("mlx failure", &fract);
	mlx_hook(fract.win_ptr, 17, 0, &close_win, &fract);
	mlx_hook(fract.win_ptr, 3, 0, &key_release, &fract);
	mlx_loop(fract.mlx_ptr);
}
