/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:45:08 by anleclab          #+#    #+#             */
/*   Updated: 2019/02/18 15:59:51 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	put_pixel(t_fract *fract, int x, int y, int iter)
{
	if (iter >= ITERATIONS)
		return ;
	fract->addr[x + y * WIDTH] = fract->col_tab[fract->color][iter];
}

void		draw_fractal(t_fract *fract)
{
	int		x;
	int		y;
	int		iter;

	ft_bzero(fract->addr, WIDTH * HEIGHT * 4);
	y = -1;
	while (++y < HEIGHT && (x = -1))
		while (++x < WIDTH)
		{
			if (fract->name == MANDELBROT)
				iter = iter_mandelbrot(coord(fract, x, y));
			else if (fract->name == JULIA)
				iter = iter_julia(fract, coord(fract, x, y));
			put_pixel(fract, x, y, iter);
		}
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->img_ptr, 0,
			0);
}
