/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:09:56 by anleclab          #+#    #+#             */
/*   Updated: 2019/02/14 10:42:07 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "mlx.h"
#include "fdf.h"

void	free_2d_tab(void ***tab, int len)
{
	int		i;

	if (*tab)
	{
		i = -1;
		while (++i < len)
		{
			free((*tab)[i]);
			(*tab)[i] = NULL;
		}
	}
	free(*tab);
	*tab = NULL;
}

void	clear_fdf(t_fdf *fdf)
{
	if (!fdf)
		return ;
	free_2d_tab((void ***)&(fdf->map), fdf->depth);
	free_2d_tab((void ***)&(fdf->proj), fdf->depth);
	if (fdf->mlx_ptr && fdf->img_ptr)
	{
		mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
		fdf->img_ptr = NULL;
	}
	fdf->addr = NULL;
	if (fdf->mlx_ptr && fdf->win_ptr)
	{
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		fdf->win_ptr = NULL;
	}
}

void	error(char *str, t_fdf *fdf)
{
	ft_putstr(str);
	ft_putchar('\n');
	clear_fdf(fdf);
	exit(0);
}
