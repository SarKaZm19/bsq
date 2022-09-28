/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:13:12 by yhuberla          #+#    #+#             */
/*   Updated: 2022/09/27 13:36:37 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"

void	ft_display_map(char **mp, t_bsq *params)
{
	int	index;

	index = 0;
	while (index < params->nb_lines)
	{
		ft_putstr(mp[index]);
		ft_putstr("\n");
		index ++;
	}
}
