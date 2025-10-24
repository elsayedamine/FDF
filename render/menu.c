/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 02:21:27 by sayed             #+#    #+#             */
/*   Updated: 2025/10/24 19:52:18 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	paint_menu(t_all *var)
{
	int		i;
	int		j;
	char	*dst;

	j = 0;
	while (j < var->menu.h)
	{
		i = 0;
		while (i < var->menu.w)
		{
			dst = var->menu.addr + (j * var->menu.line_length + i
					* (var->menu.bits_per_pixel / 8));
			*(unsigned int *)dst = get_color(0x868686, 0x696969, (i + j) * 3);
			i++;
		}
		j++;
	}
}

void	menu(t_all *var)
{
	int	i;

	i = 0;
	var->menu.w = M_WIDTH / 5;
	var->menu.h = M_HEIGHT;
	if (var->menu.img)
		mlx_destroy_image(var->win.mlx, var->menu.img);
	var->menu.img = mlx_new_image(var->win.mlx, var->menu.w, var->menu.h);
	var->menu.addr = mlx_get_data_addr(var->menu.img, \
		&var->menu.bits_per_pixel, &var->menu.line_length, \
			&var->menu.endian);
	paint_menu(var);
	mlx_put_image_to_window(var->win.mlx, var->win.win, var->menu.img, 0, 0);
	while (i < 5)
		fill_rectangle(var, M_WIDTH / 6.5, 50 + (40 * i++), 75);
	i = 0;
	while (i < 5)
		fill_rectangle(var, 15, 50 + (40 * i++), 115);
	fill_rectangle(var, M_WIDTH / 12 - 27, 1, 120);
	fill_square(var, 15, M_HEIGHT / 4 - 10);
	put_info_on_menu(var);
}
