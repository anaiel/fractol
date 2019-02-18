/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:13:25 by anleclab          #+#    #+#             */
/*   Updated: 2019/02/18 17:20:23 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_rainbow(t_fract *fract)
{
	int		i;

	i = -1;
	while (++i < ITERATIONS)
		if (i < ITERATIONS / 3)
			fract->col_tab[RAINBOW][i] = gradient(3 * i / ITERATIONS, R_1, R_2);
		else if (i < 2 * ITERATIONS / 3)
			fract->col_tab[RAINBOW][i] = gradient(3 * i / ITERATIONS - 1, R_2,
					R_3);
		else
			fract->col_tab[RAINBOW][i] = gradient(3 * (i - 2 * ITERATIONS / 3)
					/ ITERATIONS, R_3, R_1);
}

void		init_col_tab(t_fract *fract)
{
	int		i;

	i = -1;
	while (++i < ITERATIONS)
	{
		fract->col_tab[BLACK_N_WHITE][i] = 0xFFFFFF;
		if (i < ITERATIONS / 200)
			fract->col_tab[BLUE_TO_ORANGE][i] = B2O_1;
		else if (i < 2 * ITERATIONS / 200)
			fract->col_tab[BLUE_TO_ORANGE][i] = B2O_2;
		else if (i < 3 * ITERATIONS / 200)
			fract->col_tab[BLUE_TO_ORANGE][i] = B2O_3;
		else if (i < 4 * ITERATIONS / 200)
			fract->col_tab[BLUE_TO_ORANGE][i] = B2O_4;
		else
			fract->col_tab[BLUE_TO_ORANGE][i] = B2O_5;
	}
	init_rainbow(fract);
}
