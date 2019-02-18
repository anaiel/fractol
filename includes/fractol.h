/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:25:34 by anleclab          #+#    #+#             */
/*   Updated: 2019/02/18 11:16:56 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include "keys.h"
# include "math.h"

# define SIZE 250
# define HEIGHT 2 * SIZE
# define WIDTH 3 * SIZE
# define ITERATIONS 1000

# define EXIT_ERROR 1
# define EXIT_OK 0

typedef struct	s_point
{
	double	x;
	double	y;
}				t_point;

typedef enum	e_name
{
	MANDELBROT,
	JULIA,
	NONE
}				t_name;

typedef struct	s_image
{
	int		bpp;
	int		size_line;
	int		endian;
}				t_image;

typedef struct	s_fract
{
	t_name			name;
	unsigned int	*addr;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	t_image			image;
}				t_fract;

t_name		which_fractal(char *str);
void		draw_fractal(t_fract *fract);
void		end(t_fract *fract, int end_status);

int			close_win(t_fract *fract);
int			key_release(int key, t_fract *fract);

t_point		coord(t_fract *fract, int x, int y);

int			is_mandelbrot(t_point c);

int			new_image(t_fract *fract);

t_point		c_add(t_point a, t_point b);
t_point		c_mult(t_point a, t_point b);
t_point		c_sq(t_point a);
double		c_mod(t_point a);

#endif
