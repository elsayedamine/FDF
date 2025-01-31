/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 23:01:33 by aelsayed          #+#    #+#             */
/*   Updated: 2025/01/21 18:10:59 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_scale(t_scl *scale)
{
	scale->x = 17;
	scale->y = 20;
	scale->z = 2;
	scale->x_offset = M_WIDTH * 450 / 1000;
	scale->y_offset = M_HEIGHT * 250 / 1000;
	scale->rot = 0;
}

void	zoom(t_all *var, float x, char c)
{
	if (c == '*')
	{
		var->scale.x *= (1 + x);
		var->scale.y *= (1 + x);
		var->scale.z *= (1 + x);
	}
	else if (c == '/' && var->scale.x > 1 && var->scale.y > 1)
	{
		var->scale.x /= (1 + x);
		var->scale.y /= (1 + x);
		var->scale.z /= (1 + x);
	}
	draw(var);
}

void	iskey(t_all *var, int key)
{
	if (key == 'p')
		var->scale.proj = 'p';
	if (key == 'i')
		var->scale.proj = 'i';
	if (key == 'c')
		fill_scale(&var->scale);
	if (key == 'z')
		var->scale.z += 1;
	if (key == 'x')
		var->scale.z -= 1;
	draw(var);
}

int	keyhook(int key, t_all *var)
{
	if (key == 65307)
		ft_close(var);
	if (key == 65451 || key == 65453)
	{
		if (key == 65451)
			zoom(var, 0.2, '*');
		if (key == 65453)
			zoom(var, 0.2, '/');
	}
	if (ft_strchr_index("cxzpi", key) != -1)
		iskey(var, key);
	if (colorcheck(key))
		paint(key, var);
	if (key == '1' || key == '2')
	{
		if (key == '1')
			var->scale.rot += 1;
		if (key == '2')
			var->scale.rot -= 1;
		draw(var);
	}
	return (0);
}
