/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:15:20 by kali              #+#    #+#             */
/*   Updated: 2025/01/21 18:25:44 by aelsayed         ###   ########.fr       */
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
	int			**color;
	int			c;
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

typedef struct s_all
{
	t_vec		crd;
	t_scl		scale;
	t_window	win;
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
	char		*color;
	char		*rgb;
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

void			feed_tab(char **file, int lines, t_all *vars);

// line functions
int				ft_color(const char *s);
int				colorcheck(int key);
void			set_seperate(t_all *var, int color);
void			paint(int key, t_all *var);
void			draw(t_all *var);
void			draw_shape_rot(t_all *var, int flag);
void			draw_shape(t_all *var, int flag);
void			draw_parallel(t_all *var, int flag);
void			draw_line_segment(t_window *window, t_vec crd);
void			fill_scale(t_scl *scale);

// hook functions
void			put_on_window(t_all *var);
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