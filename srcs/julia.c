/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:43:08 by anleclab          #+#    #+#             */
/*   Updated: 2019/02/18 18:13:09 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_point	julia(t_fract *fract, t_point c)
{
	return (c_add(c_sq(c), fract->julia));
}

int				iter_julia(t_fract *fract, t_point c)
{
	t_point		jul;
	int			i;

	jul.x = c.x;
	jul.y = c.y;
	i = -1;
	while (++i < ITERATIONS)
	{
		jul = julia(fract, jul);
		if (c_sqmod(jul) > 4)
			return (i);
	}
	return (ITERATIONS);
}
