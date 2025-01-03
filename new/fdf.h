/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:01:03 by aelsayed          #+#    #+#             */
/*   Updated: 2025/01/03 23:39:45 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx-linux/mlx.h"
# include "../LIBFT/libft.h"
# include <math.h>

# define M_PI 3.14159265358979323846

typedef struct s_coordinates
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	**color;
	int	c;
	int	**tab;
	int	lines;
	int	columns;
}				t_vec;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

int	ft_color(const char *s);

#endif