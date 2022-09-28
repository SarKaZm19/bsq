/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:22:50 by flvasten          #+#    #+#             */
/*   Updated: 2021/08/05 17:20:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"

char			*ft_substr(char *s, int start, int len, int n_free)
{
	char		*tmp;

	if (len < 0)
		len = ft_strlen(s);
	if ((tmp = (char *)malloc(sizeof(*tmp) * (len + 1))))
	{
		tmp[len] = 0;
		ft_memcpy(tmp, s + start, len);
	}
	if (n_free || !tmp)
		free(s);
	return (tmp);
}

int				get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buff;
	int			ret;

	buff = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line || read(fd, NULL, 0) || !buff || BUFFER_SIZE <= 0)
		return (free_return(&buff, -1));
	ret = 1;
	while (get_index(save, '\n') < 0 && ret != 0)
	{
		ret = (int)read(fd, buff, BUFFER_SIZE);
		buff[ret] = '\0';
		if (!(save = ft_strjoin(save, buff)))
			return (free_return(&buff, -1));
	}
	free(buff);
	if (!(*line = ft_substr(save, 0, get_index(save, '\n'), 0)))
		return (-1);
	if (!(save = ft_substr(save, get_index(save, '\n') + 1,
					ft_strlen(save) - get_index(save, '\n'), 1)))
		return (free_return(line, -1));
	if (ret == 0)
		return (free_return(&save, 0));
	return (1);
}
