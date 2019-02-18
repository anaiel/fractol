/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:31:46 by anleclab          #+#    #+#             */
/*   Updated: 2019/02/18 14:07:28 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_event(int button, int x, int y, t_fract *fract)
{
	(void)x;
	(void)y;
	if (button == MOUSE_SCROLL_UP)
	{
		if (fract->mode == COLOR)
			fract->color = (fract->color + 1) % NB_COLOR_SCHEMES;
		else if (fract->mode == ZOOM)
			fract->zoom *= 0.9;
	}
	else if (button == MOUSE_SCROLL_DOWN)
	{
		if (fract->mode == COLOR)
			fract->color = (fract->color == 0) ? NB_COLOR_SCHEMES - 1
				: fract->color - 1;
		else if (fract->mode == ZOOM)
			fract->zoom *= 1.1;
	}
	draw_fractal(fract);
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->img_ptr, 0,
			0);
	return (0);
}

int		close_win(t_fract *fract)
{
	end(fract, EXIT_OK);
	return (0);
}

int		key_release(int key, t_fract *fract)
{
	if (key == ESC)
		end(fract, EXIT_OK);
	if (key == C)
		fract->mode = (fract->mode + 1) % 2;
	return (0);
}
