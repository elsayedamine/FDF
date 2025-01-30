/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:43:44 by kali              #+#    #+#             */
/*   Updated: 2025/01/19 16:44:36 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_valid(const char c)
{
	char	*str;
	int		i;

	i = 0;
	str = "0123456789abcdef";
	while (str[i])
	{
		if (c == str[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_color(const char *s)
{
	int	i;
	int	color;

	color = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i] != ',' && s[i])
		i++;
	if (!s[i])
		return (0xffffff);
	i++;
	if (s[i] == '0' && s[i + 1] == 'x')
	{
		i += 2;
		while (s[i] && is_valid(s[i]) != -1)
			color = (color * 16) + is_valid(s[i++]);
		return (color);
	}
	else
		return (0xffffff);
}

int	colorcheck(int key)
{
	if (key == 'w')
		return (0xffffff);
	if (key == 'b')
		return (0x0000ff);
	if (key == 'r')
		return (0xff0000);
	if (key == 'g')
		return (0x00ff00);
	if (key == 'y')
		return (0xffff00);
	if (key == 't')
		return (0x00ffff);
	if (key == 'o')
		return (0xffa100);
	return (0);
}

void	paint(int key, t_all *var)
{
	int	i;
	int	j;

	i = 0;
	while (i < var->crd.lines)
	{
		j = 0;
		while (j < var->crd.columns)
			var->crd.color[i][j++] = colorcheck(key);
		i++;
	}
	draw(var);
}
