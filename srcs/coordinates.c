/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:32:01 by anleclab          #+#    #+#             */
/*   Updated: 2019/02/18 18:14:58 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_point		coord(t_fract *fract, int x, int y)
{
	t_point		res;
	
	if (fract->name == MANDELBROT)
	{
		res.x = fract->zoom * (((double)x / SIZE) - 2);
		res.y = fract->zoom * ((-(double)y / SIZE) + 1);
	}
	else
	{
		res.x = fract->zoom * (((double)x / SIZE) - 1.5);
		res.y = fract->zoom * ((-(double)y / SIZE) + 1);
	}
	return (res);
}
