/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:41:33 by anleclab          #+#    #+#             */
/*   Updated: 2019/02/15 17:07:08 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_name	which_fractal(char *str)
{
	if (ft_strequ(str, "mandelbrot") || ft_strequ(str, "man"))
		return (MANDELBROT);
	if (ft_strequ(str, "julia") || ft_strequ(str, "jul"))
		return (JULIA);
	return (NONE);
}
