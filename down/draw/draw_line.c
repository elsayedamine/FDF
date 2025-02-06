/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:27:32 by aelsayed          #+#    #+#             */
/*   Updated: 2025/02/06 19:28:18 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

unsigned int	get_color(unsigned int start, unsigned int end, float t)
{
	t_color	color;

	color.r = (start >> 16) & 0xFF;
	color.g = (start >> 8) & 0xFF;
	color.b = start & 0xFF;
	color.r2 = (end >> 16) & 0xFF;
	color.g2 = (end >> 8) & 0xFF;
	color.b2 = end & 0xFF;
	color.r_interp = color.r + (int)((color.r2 - color.r) * t);
	color.g_interp = color.g + (int)((color.g2 - color.g) * t);
	color.b_interp = color.b + (int)((color.b2 - color.b) * t);
	return (((color.r_interp & 0xFF) << 16) | \
		((color.g_interp & 0xFF) << 8) | (color.b_interp & 0xFF));
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
		if (x >= 0 && x < M_WIDTH && x < window->line_length / 4 && \
			y >= 0 && y < M_HEIGHT)
		{
			dst = window->addr + ((int)y * window->line_length + (int)x
					* (window->bits_per_pixel / 8));
			*(unsigned int *)dst = get_color(crd.c, crd.c_end, \
				(float)i / steps);
		}
		i++;
	}
}
