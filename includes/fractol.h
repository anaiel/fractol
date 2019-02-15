/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:25:34 by anleclab          #+#    #+#             */
/*   Updated: 2019/02/15 16:43:53 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include "keys.h"

# define HEIGHT 500
# define WIDTH 500
# define EXIT_ERROR 1
# define EXIT_OK 0

typedef struct	s_image
{
	int		bpp;
	int		size_line;
	int		endian;
}				t_image;

typedef struct	s_fract
{
	char			name;
	unsigned int	*addr;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	t_image			image;
}				t_fract;

char	which_fractal(char *str);
void	end(t_fract *fract, int end_status);

int		close_win(t_fract *fract);
int		key_release(int key, t_fract *fract);

#endif
