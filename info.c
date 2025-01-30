/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 04:11:02 by aelsayed          #+#    #+#             */
/*   Updated: 2025/01/21 18:15:53 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_seperate(t_all *var, int color)
{
	int	y;
	int	loc;

	y = 0;
	loc = M_WIDTH * 12 / 100 - 1;
	while (y < M_HEIGHT)
		mlx_pixel_put(var->win.mlx, var->win.win, loc, y++, color);
	y = 0;
	while (y < M_HEIGHT)
		mlx_pixel_put(var->win.mlx, var->win.win, loc - 1, y++, color);
}

void	fill_info(t_info *info, t_all *var)
{
	info->x = ft_itoa(var->scale.x_offset);
	info->y = ft_itoa(var->scale.y_offset);
	info->z = ft_itoa(var->scale.z);
	info->zoom = "Keys (+/-) : Zoom In/Out";
	info->height = "keys (Z/X) : Height";
	info->center = "Key (C) : Center Model";
	info->escape = "Key (Esc) : Exit";
	info->transl = "Left Ms & Drag : Translate";
	info->proj = "Keys (I/P) : Isometric / Parallel";
	info->rot = "Right Ms & Drag : Rotate";
	info->color = "Keys (R,G,B,W,Y,O,T) : Colors";
	info->rgb = ft_itoa(var->crd.color[0][0]);
}

void	put_strings(t_all *var, t_info info)
{
	mlx_string_put(var->win.mlx, var->win.win, 80, 20, 0x00ffff, "<Controls>");
	mlx_string_put(var->win.mlx, var->win.win, 20, 40, 0xffa500, info.zoom);
	mlx_string_put(var->win.mlx, var->win.win, 20, 60, 0xffa500, info.height);
	mlx_string_put(var->win.mlx, var->win.win, 20, 80, 0xffa500, info.center);
	mlx_string_put(var->win.mlx, var->win.win, 20, 100, 0xffa500, info.proj);
	mlx_string_put(var->win.mlx, var->win.win, 20, 120, 0xffa500, info.escape);
	mlx_string_put(var->win.mlx, var->win.win, 20, 140, 0xffa500, info.transl);
	mlx_string_put(var->win.mlx, var->win.win, 20, 160, 0xffa500, info.rot);
	mlx_string_put(var->win.mlx, var->win.win, 20, 180, 0xffa500, info.color);
	mlx_string_put(var->win.mlx, var->win.win, 80, 210, 0x00ffff, "<Status>");
}

void	put_on_window(t_all *var)
{
	t_info	info;

	fill_info(&info, var);
	put_strings(var, info);
	info.join = ft_strjoin("X offset : ", info.x);
	mlx_string_put(var->win.mlx, var->win.win, 20, 230, 0xffa500, info.join);
	ft_free("1", info.join);
	info.join = ft_strjoin("Y offset : ", info.y);
	mlx_string_put(var->win.mlx, var->win.win, 20, 250, 0xffa500, info.join);
	ft_free("1", info.join);
	info.join = ft_strjoin("Z value  : ", info.z);
	mlx_string_put(var->win.mlx, var->win.win, 20, 270, 0xffa500, info.join);
	ft_free("1", info.join);
	info.join = ft_strjoin("Color Value : ", info.rgb);
	mlx_string_put(var->win.mlx, var->win.win, 20, 290, 0xffa500, info.join);
	ft_free("11111", info.x, info.y, info.z, info.rgb, info.join);
}
