/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:13:25 by anleclab          #+#    #+#             */
/*   Updated: 2019/02/18 12:37:41 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	color_b2o(int iter)
{
	if (iter < ITERATIONS / 200)
		return (B2O_1);
	else if (iter < 2 * ITERATIONS / 200)
		return (B2O_2);
	else if (iter < 3 * ITERATIONS / 200)
		return (B2O_3);
	else if (iter < 4 * ITERATIONS / 200)
		return (B2O_4);
	else
		return (B2O_5);
}

int			color(t_fract *fract, int iter)
{
	if (fract->color == BLUE_TO_ORANGE)
		return(color_b2o(iter));
	return(0xFFFFFF);
}
