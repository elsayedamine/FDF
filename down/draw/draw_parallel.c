/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_parallel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:14:10 by aelsayed          #+#    #+#             */
/*   Updated: 2025/02/06 19:16:51 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	get_crd_colomns_p(t_all *strct, int i, int j)
{
	strct->crd.x0 = strct->scale.x_offset + (i * strct->scale.x);
	strct->crd.y0 = strct->scale.y_offset + (j * strct->scale.y);
	strct->crd.x1 = strct->scale.x_offset + ((i + 1) * strct->scale.x);
	strct->crd.y1 = strct->scale.y_offset + (j * strct->scale.y);
	strct->crd.c_end = strct->crd.color[j][i + 1];
	draw_line_segment(&strct->win, strct->crd);
}

void	get_crd_lines_p(t_all *strct, int i, int j)
{
	strct->crd.x0 = strct->scale.x_offset + (i * strct->scale.x);
	strct->crd.y0 = strct->scale.y_offset + (j * strct->scale.y);
	strct->crd.x1 = strct->scale.x_offset + (i * strct->scale.x);
	strct->crd.y1 = strct->scale.y_offset + ((j + 1) * strct->scale.y);
	strct->crd.c_end = strct->crd.color[j + 1][i];
	draw_line_segment(&strct->win, strct->crd);
}

void	draw_parallel(t_all *var, int flag)
{
	int	i;
	int	j;

	j = 0;
	var->scale.proj = 'p';
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
				get_crd_colomns_p(var, i, j);
			if (j + 1 < var->crd.lines)
				get_crd_lines_p(var, i, j);
			i++;
		}
		j++;
	}
	hook_manipulation(var);
}

void	draw(t_all *var)
{
	if (var->scale.proj == 'p')
		draw_parallel(var, 1);
	else if (var->scale.rot)
		draw_shape_rot(var, 1);
	if (var->scale.proj == 'i')
		draw_shape(var, 1);
}
