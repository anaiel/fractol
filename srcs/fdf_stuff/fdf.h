/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:55:35 by dtrigalo          #+#    #+#             */
/*   Updated: 2019/02/08 18:31:56 by anleclab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_HEIGHT 1200
# define WIN_WIDTH 1200
# define MARGIN 200
# define BUFFER_SIZE 4096

# define MENU_COLOR 0xDDDDDD
# define MOUSE_ROTATION_COEF 0.005
# define ANGLE_INCR 0.02
# define OFFSET_INCR 10
# define ZOOM_INCR 0.2
# define ALT_INCR 0.1

# define INT_MAX 2147483647

typedef enum	e_proj_type
{
	ISOMETRIC,
	PARALLEL,
	TOP
}				t_proj_type;

typedef enum	e_color
{
	ALTITUDE,
	MAP,
	RAINBOW,
	FANCY_RAINBOW,
	MONO
}				t_color;

typedef struct	s_ipos
{
	int		i;
	int		j;
}				t_ipos;

typedef struct	s_mouse
{
	int	pressed;
	int	last_x;
	int	last_y;
	int	x;
	int	y;

}				t_mouse;

typedef struct	s_point
{
	double	x;
	double	y;
	double	z;
	int		color;
}				t_point;

typedef struct	s_image
{
	int		bpp;
	int		size_line;
	int		endian;
}				t_image;

typedef struct	s_fdf
{
	unsigned int	*addr;
	int				**map;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	t_point			**proj;
	t_mouse			mouse;
	t_image			image;
	int				rainbow;
	int				printed;
	int				width;
	int				depth;
	double			xmax;
	double			xmin;
	double			ymax;
	double			ymin;
	int				zmax;
	int				zmin;
	double			scale;
	int				x_offset;
	int				y_offset;
	double			alt_ratio;
	t_proj_type		proj_type;
	t_color			color_scheme;
	double			alpha;
	double			beta;
	double			gamma;
}				t_fdf;

int				reader(char *file_name, t_fdf *fdf);

int				projection(t_fdf *fdf);
void			isometric_projection(t_fdf *fdf, int i, int j);
void			parallel_projection(t_fdf *fdf, int i, int j);
void			top_projection(t_fdf *fdf, int i, int j);
void			rotate_x(double *y, double *z, double alpha);
void			rotate_y(double *x, double *z, double beta);
void			rotate_z(double *x, double *y, double gamma);

void			get_placement_info(t_fdf *fdf);

int				new_image(t_fdf *fdf);

void			draw_image(t_fdf *fdf);
t_ipos			get_ipos(int i, int j);
void			draw_point(t_fdf *fdf);
int				apply_color(t_fdf *fdf, t_ipos p1, t_ipos p2, t_point p);
int				gradient(t_fdf *fdf, t_point p, t_point p1, t_point p2);
int				y_gradient(t_point p, t_point p1, t_point p2);
int				z_gradient(double ratio, int start_col, int end_col);
double			percent(double current, double start, double end);
void			fill_pixel(t_fdf *fdf, t_point p);

void			print_command_menu(t_fdf fdf);

int				red_cross_closing(t_fdf *fdf);
int				key_press(int key, t_fdf *fdf);
int				key_release(int key, t_fdf *fdf);
int				mouse_press(int button, int x, int y, t_fdf *fdf);
int				mouse_release(int button, int x, int y, t_fdf *fdf);
int				mouse_move(int x, int y, t_fdf *fdf);

void			reset_color(t_fdf *fdf);

void			event_move(int key, t_fdf *fdf);
void			event_zoom(int key, double *scale);
void			event_rotate(int key, t_fdf *fdf);
void			event_adjust_alt(int key, double *alt);
void			event_reset(t_fdf *fdf);
void			event_rainbow(t_fdf *fdf);
void			alt_and_move(int key, t_fdf *fdf);

void			error(char *str, t_fdf *fdf);
void			free_2d_tab(void ***tab, int len);
void			clear_fdf(t_fdf *fdf);

int				is_valid_mapchar(char c);

#endif
