/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:45:25 by kali              #+#    #+#             */
/*   Updated: 2025/01/21 17:47:25 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line_segment(t_window *window, t_vec crd)
{
	int		i;
	float	x;
	float	y;
	int		steps;
	char	*dst;

	i = 0;
	steps = 500;
	while (i <= steps)
	{
		x = crd.x0 + (float)i / steps * (crd.x1 - crd.x0);
		y = crd.y0 + (float)i / steps * (crd.y1 - crd.y0);
		if (x >= 0 && x < window->line_length / 4 && y >= 0 && y < M_HEIGHT)
		{
			dst = window->addr + ((int)y * window->line_length + (int)x
					* (window->bits_per_pixel / 8));
			*(unsigned int *)dst = crd.c;
		}
		i++;
	}
}

void	get_crd_colomns(t_all *strct, int i, int j)
{
	strct->crd.x0 = strct->scale.x_offset + (i * strct->scale.x - j
			* strct->scale.y) * cos(M_PI / 4.77);
	strct->crd.y0 = strct->scale.y_offset + (i * strct->scale.x + j
			* strct->scale.y) * sin(M_PI / 4.77) - (strct->crd.tab[j][i]
			* strct->scale.z);
	strct->crd.x1 = strct->scale.x_offset + ((i + 1) * strct->scale.x - j
			* strct->scale.y) * cos(M_PI / 4.77);
	strct->crd.y1 = strct->scale.y_offset + ((i + 1) * strct->scale.x + j
			* strct->scale.y) * sin(M_PI / 4.77) - (strct->crd.tab[j][i + 1]
			* strct->scale.z);
	draw_line_segment(&strct->win, strct->crd);
}

void	get_crd_lines(t_all *strct, int i, int j)
{
	strct->crd.x0 = strct->scale.x_offset + (i * strct->scale.x - j
			* strct->scale.y) * cos(M_PI / 4.77);
	strct->crd.y0 = strct->scale.y_offset + (i * strct->scale.x + j
			* strct->scale.y) * sin(M_PI / 4.77) - (strct->crd.tab[j][i]
			* strct->scale.z);
	strct->crd.x1 = strct->scale.x_offset + (i * strct->scale.x - (j + 1)
			* strct->scale.y) * cos(M_PI / 4.77);
	strct->crd.y1 = strct->scale.y_offset + (i * strct->scale.x + (j + 1)
			* strct->scale.y) * sin(M_PI / 4.77) - (strct->crd.tab[j + 1][i]
			* strct->scale.z);
	draw_line_segment(&strct->win, strct->crd);
}

void	draw_shape(t_all *var, int flag)
{
	int	i;
	int	j;

	j = 0;
	var->scale.proj = 'i';
	initialisation(var, flag);
	if (!var->win.mlx || !var->win.win)
		return ;
	while (j < var->crd.lines)
	{
		i = 0;
		while (i < var->crd.columns)
		{
			var->crd.c = var->crd.color[j][i];
			if (i + 1 < var->crd.columns)
				get_crd_colomns(var, i, j);
			if (j + 1 < var->crd.lines)
				get_crd_lines(var, i, j);
			i++;
		}
		j++;
	}
	hook_manipulation(var);
}
