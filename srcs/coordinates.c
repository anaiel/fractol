/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:32:01 by anleclab          #+#    #+#             */
/*   Updated: 2019/02/15 18:18:31 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_point		coord(t_fract *fract, int x, int y)
{
	t_point		res;

	if (fract->name == MANDELBROT)
	{
		res.x = (x * 3 / WIDTH) - 2;
		res.y = (-y * 2 / HEIGHT) + 1;
	}
	else
	{
		res.x = 0;
		res.y = 0;
	}
	return (res);
}
