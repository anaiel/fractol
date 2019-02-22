/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:31:46 by anleclab          #+#    #+#             */
/*   Updated: 2019/02/22 10:40:55 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_event(int button, int x, int y, t_fract *fract)
{
	if (button != MOUSE_SCROLL_UP && button != MOUSE_SCROLL_DOWN)
		return (0);
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
	else if (key == C)
		fract->mode = (fract->mode + 1) % 2;
	else if (key == SPACE || (fract->name == JULIA && (key == DOWN_ARROW
					|| key == UP_ARROW || key == RIGHT_ARROW
					|| key == LEFT_ARROW)))
	{
		if (key == SPACE)
			fract->color = (fract->color + 1) % NB_COLOR_SCHEMES;
		if (key == DOWN_ARROW)
			fract->julia.y *= 0.99;
		if (key == UP_ARROW)
			fract->julia.y *= 1.01;
		if (key == LEFT_ARROW)
			fract->julia.x *= 0.99;
		if (key == RIGHT_ARROW)
			fract->julia.x *= 1.01;
		draw_fractal(fract);
		mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->img_ptr,
				0, 0);
	}
	return (0);
}
