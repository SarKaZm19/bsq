/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvasten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:40:25 by flvasten          #+#    #+#             */
/*   Updated: 2021/03/25 13:11:23 by flvasten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"

int			free_return(char **str, int ret_value)
{
	if (*str)
		free(*str);
	*str = NULL;
	return (ret_value);
}

int			get_index(char *s, char c)
{
	int		i;

	if (!s)
		return (-1);
	i = -1;
	while (s[++i])
		if (s[i] == c)
			return (i);
	if (s[i] == c)
		return (i);
	return (-1);
}

int			ft_strlen(char *s)
{
	if (s)
		return (get_index(s, 0));
	return (0);
}

void		*ft_memcpy(void *dest, void *src, int n)
{
	if (!dest && !src)
		return (0);
	while (n--)
		*((unsigned char *)dest + n) = *((unsigned char *)src + n);
	return (dest);
}

char		*ft_strjoin(char *s1, char *s2)
{
	int		size;
	char	*tmp;

	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(tmp = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memcpy(tmp, s1, ft_strlen(s1));
	ft_memcpy(tmp + ft_strlen(s1), s2, ft_strlen(s2));
	tmp[size] = 0;
	if (s1)
		free(s1);
	return (tmp);
}
