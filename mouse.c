/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 20:03:14 by aelsayed          #+#    #+#             */
/*   Updated: 2025/01/20 17:19:17 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_press(int button, int x, int y, t_all *var)
{
	if (button == 1)
	{
		var->scale.x_ms = x;
		var->scale.y_ms = y;
		var->scale.mouse_pressed = 1;
	}
	return (0);
}

int	mouse_release(int button, int x, int y, t_all *var)
{
	if (button == 1)
	{
		(void)x;
		(void)y;
		var->scale.mouse_pressed = 0;
	}
	return (0);
}

int	mouse_move(int x, int y, t_all *var)
{
	if (var->scale.mouse_pressed)
	{
		var->scale.x_offset += x - var->scale.x_ms;
		var->scale.y_offset += y - var->scale.y_ms;
		var->scale.x_ms = x;
		var->scale.y_ms = y;
		draw(var);
	}
	return (0);
}
