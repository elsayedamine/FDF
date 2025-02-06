/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayed <sayed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 04:11:02 by aelsayed          #+#    #+#             */
/*   Updated: 2025/02/06 04:03:36 by sayed            ###   ########.fr       */
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

void	Controls(t_all *var, t_info info)
{
	int	w;
	int	i;

	w = M_WIDTH / 10;
	i = M_HEIGHT / 4 + 30;
	mlx_string_put(var->win.mlx, var->win.win,
					M_WIDTH / 12, M_HEIGHT / 4 + 25, 0x007aff, "<Controls>");
	mlx_string_put(var->win.mlx, var->win.win,
					w - ft_strlen(info.zoom) * 3, 80 + i, 0xff4c4c, info.zoom);
	mlx_string_put(var->win.mlx, var->win.win,
					w - ft_strlen(info.height) * 3, 40 + i, 0xff4c4c, info.height);
	mlx_string_put(var->win.mlx, var->win.win,
					w - ft_strlen(info.center) * 3, 100 + i, 0xff4c4c, info.center);
	mlx_string_put(var->win.mlx, var->win.win,
					w - ft_strlen(info.proj) * 3, 120 + i, 0xff4c4c, info.proj);
	mlx_string_put(var->win.mlx, var->win.win,
					w - ft_strlen(info.escape) * 3, 20 + i, 0xff4c4c, info.escape);
	mlx_string_put(var->win.mlx, var->win.win,
					w - ft_strlen(info.transl) * 3, 140 + i, 0xff4c4c, info.transl);
	mlx_string_put(var->win.mlx, var->win.win,
					w - ft_strlen(info.rot) * 3, 60 + i, 0xff4c4c, info.rot);
}

void	Status(t_all *var, t_info info)
{
	mlx_string_put(var->win.mlx, var->win.win,
					M_WIDTH / 12 + 10, 20, 0x007aff, "<Status>");
	mlx_string_put(var->win.mlx, var->win.win,
					50, 70, 0xff4c4c, "X-OFFSET  :");
	mlx_string_put(var->win.mlx, var->win.win,
					50, 110, 0xff4c4c, "Y-OFFSET  :");
	mlx_string_put(var->win.mlx, var->win.win,
					50, 150, 0xff4c4c, "Z-OFFSET  :");
	mlx_string_put(var->win.mlx, var->win.win,
					50, 190, 0xff4c4c, "ZOOM-SCALE  :");
	mlx_string_put(var->win.mlx, var->win.win,
					50, 230, 0xff4c4c, "ROTATION ANGLE  :");
	mlx_string_put(var->win.mlx, var->win.win,
					305, 70, 0x007aff, info.x);
	mlx_string_put(var->win.mlx, var->win.win,
					305, 110, 0x007aff, info.y);
	mlx_string_put(var->win.mlx, var->win.win,
					305, 150, 0x007aff, info.z);
	mlx_string_put(var->win.mlx, var->win.win,
					305, 190, 0x007aff, info.zm);
	mlx_string_put(var->win.mlx, var->win.win,
					305, 230, 0x007aff, info.angle);
	ft_free("11111", info.zm, info.x, info.y, info.z, info.angle);
}

void	put_info_on_menu(t_all *var)
{
	t_info	info;

	fill_info(&info, var);
	Status(var, info);
	Controls(var, info);
}
