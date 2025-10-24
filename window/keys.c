/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 23:01:33 by aelsayed          #+#    #+#             */
/*   Updated: 2025/10/24 19:51:36 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	fill_scale(t_scl *scale)
{
	scale->x = 10;
	scale->y = 10;
	scale->z = 10;
	scale->x_offset = M_WIDTH * 45 / 100;
	scale->y_offset = M_HEIGHT * 25 / 100;
	scale->rot = 0;
}

void	zoom(t_scl *scale, float x, char c)
{
	if (c == '*' && scale->z < 100 && scale->x < 1000)
	{
		scale->x *= (1 + x);
		scale->y *= (1 + x);
		scale->z *= (1 + x);
		scale->zoom++;
	}
	else if (c == '/' && scale->x > 1 && scale->y > 1)
	{
		scale->x /= (1 + x);
		scale->y /= (1 + x);
		scale->z /= (1 + x);
		scale->zoom--;
	}
}

void	iskey(t_all *var, int key)
{
	if (key == 'p')
		var->scale.proj = 'p';
	if (key == 'i')
		var->scale.proj = 'i';
	if (key == 'z')
		var->scale.z += 1;
	if (key == 'x')
		var->scale.z -= 1;
	if (key == ' ')
		fill_scale(&var->scale);
	draw(var);
}

int	keyhook(int key, t_all *var)
{
	if (key == 65307)
		ft_close(var);
	if (key == '-' || key == '=')
	{
		if (key == '=')
			zoom(&var->scale, 0.2, '*');
		if (key == '-')
			zoom(&var->scale, 0.2, '/');
		draw(var);
	}
	if (ft_strchr_index("cxzpi ", key) != -1)
		iskey(var, key);
	if (key == 'l' || key == 'r')
	{
		if (key == 'l')
			var->scale.rot += 1;
		if (key == 'r')
			var->scale.rot -= 1;
		draw(var);
	}
	return (0);
}
