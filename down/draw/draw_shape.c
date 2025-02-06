/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayed <sayed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:45:25 by kali              #+#    #+#             */
/*   Updated: 2025/02/06 16:10:41 by sayed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

unsigned int    get_color(unsigned int start, unsigned int end, float t)
{
    t_color    color;

    color.r = (start >> 16) & 0xFF;
    color.g = (start >> 8) & 0xFF;
    color.b = start & 0xFF;
    color.r2 = (end >> 16) & 0xFF;
    color.g2 = (end >> 8) & 0xFF;
    color.b2 = end & 0xFF;
    color.r_interp = color.r + (int)((color.r2 - color.r) * t);
    color.g_interp = color.g + (int)((color.g2 - color.g) * t);
    color.b_interp = color.b + (int)((color.b2 - color.b) * t);
    return ((color.r_interp & 0xFF) << 16) | ((color.g_interp & 0xFF) << 8) | (color.b_interp & 0xFF);
}

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
		if (x >= 0 && x < M_WIDTH && x < window->line_length / 4 && y >= 0 && y < M_HEIGHT)
		{
			dst = window->addr + ((int)y * window->line_length + (int)x
					* (window->bits_per_pixel / 8));
			*(unsigned int *)dst = get_color(crd.c, crd.c_end, (float)i / steps);
		}
		i++;
	}
}

void	get_crd_colomns(t_all *strct, int i, int j)
{
	strct->crd.x0 = strct->scale.x_offset + (i * strct->scale.x - j
			* strct->scale.y) * cos(M_PI / 6);
	strct->crd.y0 = strct->scale.y_offset + (i * strct->scale.x + j
			* strct->scale.y) * sin(M_PI / 6) - (strct->crd.tab[j][i]
			* strct->scale.z);
	strct->crd.x1 = strct->scale.x_offset + ((i + 1) * strct->scale.x - j
			* strct->scale.y) * cos(M_PI / 6);
	strct->crd.y1 = strct->scale.y_offset + ((i + 1) * strct->scale.x + j
			* strct->scale.y) * sin(M_PI / 6) - (strct->crd.tab[j][i + 1]
			* strct->scale.z);
	strct->crd.c_end = strct->crd.color[j][i + 1];
	draw_line_segment(&strct->win, strct->crd);
}

void	get_crd_lines(t_all *strct, int i, int j)
{
	strct->crd.x0 = strct->scale.x_offset + (i * strct->scale.x - j
			* strct->scale.y) * cos(M_PI / 6);
	strct->crd.y0 = strct->scale.y_offset + (i * strct->scale.x + j
			* strct->scale.y) * sin(M_PI / 6) - (strct->crd.tab[j][i]
			* strct->scale.z);
	strct->crd.x1 = strct->scale.x_offset + (i * strct->scale.x - (j + 1)
			* strct->scale.y) * cos(M_PI / 6);
	strct->crd.y1 = strct->scale.y_offset + (i * strct->scale.x + (j + 1)
			* strct->scale.y) * sin(M_PI / 6) - (strct->crd.tab[j + 1][i]
			* strct->scale.z);
	strct->crd.c_end = strct->crd.color[j + 1][i];
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
