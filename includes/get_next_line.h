/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvasten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:09:14 by flvasten          #+#    #+#             */
/*   Updated: 2021/03/25 13:11:11 by flvasten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

int			get_next_line(int fd, char **line);
char		*ft_substr(char *s, int start, int len, int n_free);
int			free_return(char **s, int ret_value);
int			get_index(char *s, char c);
int			ft_strlen(char *s);
void		*ft_memcpy(void *dest, void *src, int n);
char		*ft_strjoin(char *s1, char *s2);

#endif
