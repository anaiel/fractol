/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 09:00:02 by anleclab          #+#    #+#             */
/*   Updated: 2019/02/27 16:04:10 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		is_arrow(int key)
{
	return ((key == UP_ARR || key == DOWN_ARR || key == LEFT_ARR
				|| key == RIGHT_ARR));
}

int		is_letter_direction(int key)
{
	return((key == W || key == A || key == S || key == D));
}

void	change_julia_param(t_fract *fract, int key)
{
	if (key == S)
		fract->julia.y -= 0.000001;
	else if (key == W)
		fract->julia.y += 0.000001;
	else if (key == A)
		fract->julia.x -= 0.000001;
	else if (key == D)
		fract->julia.x += 0.000001;
}

void	move_fractal(t_fract *fract, int key)
{
	if (key == UP_ARR)
		fract->y_offset += fract->zoom * 0.1;
	else if (key == DOWN_ARR)
		fract->y_offset -= fract->zoom * 0.1;
	else if (key == LEFT_ARR)
		fract->x_offset -= fract->zoom * 0.1;
	else if (key == RIGHT_ARR)
		fract->x_offset += fract->zoom * 0.1;
}
