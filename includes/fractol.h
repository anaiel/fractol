/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anleclab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:25:34 by anleclab          #+#    #+#             */
/*   Updated: 2019/02/18 17:24:23 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include "keys.h"
# include "colors.h"

# define SIZE 250
# define HEIGHT 2 * SIZE
# define WIDTH 3 * SIZE
# define ITERATIONS 1000
# define NB_COLOR_SCHEMES 3

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

typedef enum	e_color
{
	BLACK_N_WHITE,
	BLUE_TO_ORANGE,
	RAINBOW
}				t_color;

typedef enum	e_mode
{
	ZOOM,
	COLOR
}				t_mode;

typedef struct	s_image
{
	int		bpp;
	int		size_line;
	int		endian;
}				t_image;

typedef struct	s_fract
{
	t_name			name;
	t_color			color;
	int				col_tab[NB_COLOR_SCHEMES][ITERATIONS];
	double			zoom;
	t_mode			mode;
	t_point			julia;
	unsigned int	*addr;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	t_image			image;
}				t_fract;

t_name			which_fractal(char *str);
void			draw_fractal(t_fract *fract);
void			end(t_fract *fract, int end_status);

int				mouse_event(int button, int x, int y, t_fract *fract);
int				close_win(t_fract *fract);
int				key_release(int key, t_fract *fract);

t_point			coord(t_fract *fract, int x, int y);

void			init_col_tab(t_fract *fract);
int				gradient(double ratio, int start, int end);

int				iter_mandelbrot(t_point c);
int				iter_julia(t_fract *fract, t_point c);

int				new_image(t_fract *fract);

t_point			c_add(t_point a, t_point b);
t_point			c_mult(t_point a, t_point b);
t_point			c_sq(t_point a);
double			c_sqmod(t_point a);

#endif
