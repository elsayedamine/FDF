/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 04:11:02 by aelsayed          #+#    #+#             */
/*   Updated: 2025/02/06 19:31:37 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	fill_info(t_info *info, t_all *var)
{
	info->x = ft_itoa(var->scale.x_offset);
	info->y = ft_itoa(var->scale.y_offset);
	info->z = ft_itoa(var->scale.z);
	info->zm = ft_itoa(var->scale.zoom);
	info->angle = ft_itoa(var->scale.rot % 360);
	info->zoom = "Zoom In/Out : (+/-)";
	info->height = "Height : (Z/X)";
	info->center = "Adjust Model : (Space)";
	info->escape = "Exit : (Esc)";
	info->transl = "Translation : Left Ms & Drag";
	info->proj = "Isometric / Parallel : (I/P)";
	info->rot = "Rotation : (L/R)";
}

void	controls(t_all *var, t_info info)
{
	int	w;
	int	i;

	w = M_WIDTH / 10;
	i = M_HEIGHT / 4 + 30;
	mlx_string_put(var->win.mlx, var->win.win, \
		M_WIDTH / 12, M_HEIGHT / 4 + 25, 0x007aff, "<Controls>");
	mlx_string_put(var->win.mlx, var->win.win, \
		w - ft_strlen(info.zoom) * 3, 80 + i, 0xffffff, info.zoom);
	mlx_string_put(var->win.mlx, var->win.win, \
		w - ft_strlen(info.height) * 3, 40 + i, 0xffffff, info.height);
	mlx_string_put(var->win.mlx, var->win.win, \
		w - ft_strlen(info.center) * 3, 100 + i, 0xffffff, info.center);
	mlx_string_put(var->win.mlx, var->win.win, \
		w - ft_strlen(info.proj) * 3, 120 + i, 0xffffff, info.proj);
	mlx_string_put(var->win.mlx, var->win.win, \
		w - ft_strlen(info.escape) * 3, 20 + i, 0xffffff, info.escape);
	mlx_string_put(var->win.mlx, var->win.win, \
		w - ft_strlen(info.transl) * 3, 140 + i, 0xffffff, info.transl);
	mlx_string_put(var->win.mlx, var->win.win, \
		w - ft_strlen(info.rot) * 3, 60 + i, 0xffffff, info.rot);
}

void	status(t_all *var, t_info info)
{
	mlx_string_put(var->win.mlx, var->win.win, \
		M_WIDTH / 12 + 10, 20, 0x007aff, "<Status>");
	mlx_string_put(var->win.mlx, var->win.win, \
		25, 70, 0xffffff, "X-OFFSET  :");
	mlx_string_put(var->win.mlx, var->win.win, \
		25, 110, 0xffffff, "Y-OFFSET  :");
	mlx_string_put(var->win.mlx, var->win.win, \
		25, 150, 0xffffff, "Z-OFFSET  :");
	mlx_string_put(var->win.mlx, var->win.win, \
		25, 190, 0xffffff, "ZOOM-SCALE  :");
	mlx_string_put(var->win.mlx, var->win.win, \
		25, 230, 0xffffff, "ROTATION ANGLE  :");
	mlx_string_put(var->win.mlx, var->win.win, \
		305, 70, 0x007aff, info.x);
	mlx_string_put(var->win.mlx, var->win.win, \
		305, 110, 0x007aff, info.y);
	mlx_string_put(var->win.mlx, var->win.win, \
		305, 150, 0x007aff, info.z);
	mlx_string_put(var->win.mlx, var->win.win, \
		305, 190, 0x007aff, info.zm);
	mlx_string_put(var->win.mlx, var->win.win, \
		305, 230, 0x007aff, info.angle);
	ft_free("11111", info.zm, info.x, info.y, info.z, info.angle);
}

void	put_info_on_menu(t_all *var)
{
	t_info	info;

	fill_info(&info, var);
	status(var, info);
	controls(var, info);
}
