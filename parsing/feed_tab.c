/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feed_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:34:33 by aelsayed          #+#    #+#             */
/*   Updated: 2025/10/24 19:52:18 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	valid_arg(char *s)
{
	int	l;

	l = ft_strlen(s) - 1;
	if (l + 1 >= 5)
	{
		if (!ft_strncmp(&s[l - 3], ".fdf", 4))
			return (1);
		else
			return (0);
	}
	return (0);
}

void	fr(int **tab, int **col, char ***split)
{
	if (tab)
		int_free("2", tab);
	if (col)
		int_free("2", col);
	if (split)
		ft_free("3", split);
}

char	***ft_alloc_all(t_all *vars, int lines, char **file)
{
	int		i;
	char	***sp_fl;
	char	*temp;

	i = 0;
	vars->crd.tab = (int **)malloc((lines + 1) * sizeof(int *));
	vars->crd.color = (int **)malloc((lines + 1) * sizeof(int *));
	sp_fl = (char ***)malloc((lines + 1) * sizeof(char **));
	if (!vars->crd.tab || !vars->crd.color || !sp_fl)
	{
		fr(vars->crd.tab, vars->crd.color, sp_fl);
		exit(1);
	}
	vars->crd.tab[lines] = NULL;
	vars->crd.color[lines] = NULL;
	while (file[i])
	{
		temp = ft_strtrim(file[i], "\n ");
		sp_fl[i] = ft_split(temp, ' ');
		free(temp);
		free(file[i]);
		i++;
	}
	sp_fl[lines] = NULL;
	return (free(file), sp_fl);
}

void	feed_tab(char **file, int lines, t_all *vars)
{
	char	***sp_fl;
	int		i;
	int		j;

	i = 0;
	sp_fl = ft_alloc_all(vars, lines, file);
	while (sp_fl[i] != NULL)
	{
		vars->crd.tab[i] = (int *)malloc(ft_arrlen(sp_fl[i]) * sizeof(int *));
		vars->crd.color[i] = (int *)malloc(ft_arrlen(sp_fl[i]) * sizeof(int *));
		if (!vars->crd.tab[i] || !vars->crd.color[i])
			return (fr(vars->crd.tab, vars->crd.color, NULL));
		j = 0;
		while (sp_fl[i][j])
		{
			vars->crd.tab[i][j] = ft_atoi(sp_fl[i][j]);
			vars->crd.color[i][j] = ft_color(sp_fl[i][j]);
			j++;
		}
		i++;
	}
	vars->crd.lines = i;
	vars->crd.columns = j;
	ft_free("3", sp_fl);
}
