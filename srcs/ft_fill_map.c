/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:32:50 by yhuberla          #+#    #+#             */
/*   Updated: 2022/09/27 14:48:59 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"

void	ft_fill_map(t_bsq *p, int size, int row, int column)
{
	int	r;
	int	c;

	r = row - (size - 1);
	while (r <= row)
	{
		c = column - (size - 1);
		while (c <= column)
		{
			(p->map)[r][c] = p->full;
			c ++;
		}
		r ++;
	}
}
