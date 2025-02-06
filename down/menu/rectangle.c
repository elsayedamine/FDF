/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectanlge.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayed <sayed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 03:49:10 by sayed             #+#    #+#             */
/*   Updated: 2025/02/06 03:54:13 by sayed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	help_rect(t_all *var, int y_offset, int color)
{
	int		x_offset;
	int		i;
	char	*dst;

	i = 0;
	x_offset = M_WIDTH / 6.5;
	while (i < 75)
	{
		dst = var->menu.addr + ((y_offset + 30) * var->menu.line_length + (x_offset + i) * (var->menu.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
		i++;
	}
	i = 0;
	while (i < 75)
	{
		dst = var->menu.addr + (y_offset * var->menu.line_length + (x_offset + i) * (var->menu.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
		i++;
	}
}

void	rectangle(t_all *var, int y_offset, int color)
{
	int		x_offset;
	int		i;
	char	*dst;

	x_offset = M_WIDTH / 6.5;
	i = 0;
	while (i < 30)
	{
		dst = var->menu.addr + ((y_offset + i) * var->menu.line_length + x_offset * (var->menu.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
		i++;
	}
	i = 0;
	while (i < 30)
	{
		dst = var->menu.addr + ((y_offset + i) * var->menu.line_length + (x_offset + 75) * (var->menu.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
		i++;
	}
	help_rect(var, y_offset, color);
}
