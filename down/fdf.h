/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:15:20 by kali              #+#    #+#             */
/*   Updated: 2025/02/06 19:26:39 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./LIBFT/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include <math.h>
# define M_PI 3.14159265358979323846
# define M_WIDTH 1920
# define M_HEIGHT 1080
# define M_THETA 0.76842396884

typedef struct s_coordinates
{
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	int			c;
	int			c_end;
	int			**color;
	int			**tab;
	int			lines;
	int			columns;
}				t_vec;

typedef struct s_scales
{
	float		x;
	float		y;
	float		z;
	int			x_offset;
	int			y_offset;
	int			x_ms;
	int			y_ms;
	int			mouse_pressed;
	int			proj;
	int			rot;
	int			zoom;
}				t_scl;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_window;

typedef struct s_menu
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			w;
	int			h;
}		t_menu;

typedef struct s_all
{
	t_vec		crd;
	t_scl		scale;
	t_window	win;
	t_menu		menu;
	char		**file;
}				t_all;

typedef struct s_info
{
	char		*x;
	char		*y;
	char		*z;
	char		*join;
	char		*zoom;
	char		*height;
	char		*transl;
	char		*escape;
	char		*center;
	char		*proj;
	char		*rot;
	char		*zm;
	char		*angle;
}				t_info;

typedef struct s_rot
{
	float		x0;
	float		y0;
	float		z0;
	float		x1;
	float		y1;
	float		z1;
}				t_rot;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
	int			r2;
	int			g2;
	int			b2;
	int			r_interp;
	int			g_interp;
	int			b_interp;
}				t_color;

// parsing functions
int				valid_arg(char *s);
void			feed_tab(char **file, int lines, t_all *vars);
int				ft_color(const char *s);

// drawing functions
void			draw(t_all *var);
void			draw_shape_rot(t_all *var, int flag);
void			draw_shape(t_all *var, int flag);
void			draw_parallel(t_all *var, int flag);
void			draw_line_segment(t_window *window, t_vec crd);
unsigned int	get_color(unsigned int start, unsigned int end, float t);
void			fill_scale(t_scl *scale);
void			zoom(t_scl *scale, float x, char c);

// menu functions
void			fill_square(t_all *var, int x_offset, int y_offset);
void			fill_rectangle(t_all *var, int x_offset, int y_offset, int len);
void			menu(t_all *vars);
void			put_info_on_menu(t_all *var);
void			rectangle(t_all *var, int offset, int color);
void			fill_rectangle(t_all *var, int x_offset, \
					int y_offset, int color);

// hook functions
int				keyhook(int keycode, t_all *var);
int				ft_close(t_all *var);
void			fr(int **tab, int **col, char ***split);
void			initialisation(t_all *var, int flag);
void			hook_manipulation(t_all *var);

// mouse functions
int				mouse_press(int button, int x, int y, t_all *var);
int				mouse_move(int x, int y, t_all *var);
int				mouse_release(int button, int x, int y, t_all *var);

#endif