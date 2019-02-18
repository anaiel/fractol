/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:21:48 by anleclab          #+#    #+#             */
/*   Updated: 2019/02/18 11:17:21 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_point	mandelbrot(t_point mand, t_point c)
{
	return(c_add(c_sq(mand), c));
}

int		is_mandelbrot(t_point c)
{
	t_point	mand;
	int		i;

	mand.x = 0;
	mand.y = 0;
	i = -1;
	while (++i < ITERATIONS)
	{
		mand = mandelbrot(mand, c);
		if (c_mod(mand) > 2)
			return (0);
	}
	return (1);
}
