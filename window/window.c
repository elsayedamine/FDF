/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:56:37 by kali              #+#    #+#             */
/*   Updated: 2025/10/24 19:52:18 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_close(t_all *var)
{
	mlx_destroy_image(var->win.mlx, var->win.img);
	mlx_destroy_image(var->win.mlx, var->menu.img);
	mlx_destroy_window(var->win.mlx, var->win.win);
	mlx_destroy_display(var->win.mlx);
	if (var->win.mlx)
		free(var->win.mlx);
	return (fr(var->crd.tab, var->crd.color, NULL), exit(0), 0);
}

void	set_to_0(t_all *var)
{
	var->scale.mouse_pressed = 0;
	var->scale.x_ms = 0;
	var->scale.y_ms = 0;
	var->scale.rot = 0;
	var->scale.zoom = 0;
	var->menu.img = 0;
}

void	initialisation(t_all *var, int flag)
{
	if (!flag)
	{
		var->win.mlx = mlx_init();
		if (!var->win.mlx)
			return ;
		var->win.win = mlx_new_window(var->win.mlx, M_WIDTH, M_HEIGHT,
				"Hello world!");
		var->win.img = mlx_new_image(var->win.mlx, M_WIDTH, M_HEIGHT);
		var->win.addr = mlx_get_data_addr(var->win.img,
				&var->win.bits_per_pixel, &var->win.line_length,
				&var->win.endian);
		set_to_0(var);
	}
	if (flag)
	{
		mlx_destroy_image(var->win.mlx, var->win.img);
		var->win.img = mlx_new_image(var->win.mlx, M_WIDTH, M_HEIGHT);
		var->win.addr = mlx_get_data_addr(var->win.img,
				&var->win.bits_per_pixel, &var->win.line_length,
				&var->win.endian);
	}
	menu(var);
}

void	hook_manipulation(t_all *var)
{
	int	loc;

	loc = M_WIDTH / 5;
	mlx_put_image_to_window(var->win.mlx, var->win.win, var->win.img, loc, 0);
	mlx_hook(var->win.win, 4, 1L << 2, mouse_press, var);
	mlx_hook(var->win.win, 5, 1L << 3, mouse_release, var);
	mlx_hook(var->win.win, 6, 1L << 6, mouse_move, var);
	mlx_key_hook(var->win.win, keyhook, var);
	mlx_hook(var->win.win, 17, 1L << 0, ft_close, var);
	mlx_loop(var->win.mlx);
}
