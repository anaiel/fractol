/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:13:25 by anleclab          #+#    #+#             */
/*   Updated: 2019/02/18 13:53:03 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_col_tab(t_fract *fract)
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
}
