/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:45:08 by anleclab          #+#    #+#             */
/*   Updated: 2019/02/18 13:51:32 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	put_pixel(t_fract *fract, int x, int y, int iter)
{
	if (iter >= ITERATIONS)
		return ;
	fract->addr[x + y * WIDTH] = fract->col_tab[fract->color][iter];
}

static void	draw_mandelbrot(t_fract *fract)
{
	int		x;
	int		y;
	int		iter;

	y = -1;
	while (++y < HEIGHT && (x = -1))
		while (++x < WIDTH)
		{
			iter = is_mandelbrot(coord(fract, x, y));
			put_pixel(fract, x, y, iter);
		}
}

void		draw_fractal(t_fract *fract)
{
	ft_bzero(fract->addr, WIDTH * HEIGHT * 4);
	if (fract->name == MANDELBROT)
		draw_mandelbrot(fract);
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->img_ptr, 0,
			0);
}
