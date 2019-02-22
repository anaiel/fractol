/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:45:08 by anleclab          #+#    #+#             */
/*   Updated: 2019/02/22 14:37:40 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	max_it(int iter)
{
	if (iter >= ITERATIONS)
		return (ITERATIONS -1);
	else if (iter < 0)
		return (0);
	else
		return (iter);
}

static void	put_pixel(t_fract *fract, int x, int y, t_felem elem)
{
	if (elem.exit >= ITERATIONS)
	{
		fract->addr[x + y * fract->width] = 0x000000;
		return ;
	}
	if (fract->color == BLACK_N_WHITE || fract->color == BLUE_TO_ORANGE
			|| fract->color == RAINBOW)
		fract->addr[x + y * fract->width]
			= fract->col_tab[fract->color][elem.exit];
	else
		fract->addr[x + y * fract->width]
			= fract->col_tab[fract->color][max_it((int)(100
			* (elem.exit - log2(log2(sqrt(c_sqmod(elem.val)))))))];
}

void		draw_fractal(t_fract *fract)
{
	int		x;
	int		y;
	t_felem	elem;

	ft_bzero(fract->addr, fract->width * fract->height * 4);
	y = -1;
	while (++y < fract->height && (x = -1))
		while (++x < fract->width)
		{
			if (fract->name == MANDELBROT)
				elem = iter_mandelbrot(coord(fract, x, y));
			else if (fract->name == JULIA)
				elem = iter_julia(fract, coord(fract, x, y));
			put_pixel(fract, x, y, elem);
		}
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->img_ptr, 0,
			0);
}
