/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_neighbours.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:04:10 by yhuberla          #+#    #+#             */
/*   Updated: 2022/09/27 15:13:32 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"

char	**ft_free_tab(char **tab, int limit)
{
	int	index;

	index = 0;
	while (index < limit)
		free(tab[index]);
	free(tab);
	return (NULL);
}

char	**ft_get_empty_tab(t_bsq *params)
{
	char	**res;
	int		index;
	int		sub_index;

	res = malloc(sizeof(*res) * params->nb_lines);
	if (!res)
		return (NULL);
	index = 0;
	while (index < params->nb_lines)
	{
		res[index] = malloc(sizeof(*res[index]) * (params->line_size + 1));
		if (!res[index])
			return (ft_free_tab(res, index));
		sub_index = 0;
		while (sub_index < params->line_size)
			res[index][sub_index ++] = '0';
		res[index][sub_index] = '\0';
		index ++;
	}
	return (res);
}

int	ft_min(int a, int b, int c)
{
	int	res;

	res = a;
	if (res > b)
		res = b;
	if (res > c)
		res = c;
	return (res);
}

void	ft_set_nb(char **tab, int r, int c, t_bsq *p)
{
	if (p->map[r][c] == p->obstacle)
		tab[r][c] = '0';
	else if (r == 0 || c == 0)
		tab[r][c] = '1';
	else
		tab[r][c] = ft_min(tab[r - 1][c], tab[r][c - 1], tab[r - 1][c - 1]) + 1;
}

int	ft_neighbours(t_bsq *params)
{
	char	**nb_tab;
	int		row;
	int		column;
	int		max[3];

	nb_tab = ft_get_empty_tab(params); //create **tab with correct size and fill it with 0
	if (!nb_tab)
		return (1);
	row = 0;
	max[0] = '1';
	max[1] = 0;
	max[2] = 0;
	while (row < params->nb_lines)
	{
		column = 0;
		while (column < params->line_size)
		{
			ft_set_nb(nb_tab, row, column, params);
			if (nb_tab[row][column] > max[0])
			{
				max[0] = nb_tab[row][column];
				max[1] = row;
				max[2] = column;
			}
			column ++;
		}
		row ++;
	}
	//ft_display_map(nb_tab, params);
	ft_fill_map(params, max[0] - '0', max[1], max[2]);
	return (0);
}
