/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:41:33 by anleclab          #+#    #+#             */
/*   Updated: 2019/02/15 16:44:35 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	which_fractal(char *str)
{
	if (ft_strequ(str, "mandelbrot") || ft_strequ(str, "man"))
		return ('m');
	if (ft_strequ(str, "julia") || ft_strequ(str, "jul"))
		return ('j');
	return (0);
}
