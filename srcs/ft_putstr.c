/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhuberla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:59:00 by yhuberla          #+#    #+#             */
/*   Updated: 2022/09/27 12:00:19 by yhuberla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"

void	ft_putstr(char *str)
{
	int	size;

	size = 0;
	while (str[size])
		size ++;
	write(1, str, size);
}
