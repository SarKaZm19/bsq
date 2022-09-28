#ifndef FT_BSQ_H
# define FT_BSQ_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
#include <sys/stat.h> 

typedef struct	s_bsq
{
	int	ret;
	int		first_line;
	int     line_size;
	int     nb_lines;
	int     fd;
	int	rd_ret;
	int	error;
	int	buffer_size;
	int	map_col;
	int	map_row;
	int	save_index;
	char    empty;
	char    obstacle;
	char    full;
	char	*save;
	char    **map;
}               t_bsq;


int	ft_get_first_line(t_bsq *params, char *save);
t_bsq	*ft_build_map(t_bsq *params);
t_bsq	*ft_free_exit(t_bsq *params);
int	ft_has_nl(char *str, int trigger, int index);
int	ft_strlen(char *str);
int		ft_neighbours(t_bsq *params);
char	*ft_strjoin(char *save, char *buff);
t_bsq	*ft_free_return(t_bsq *params, char *str);
t_bsq	*ft_init_struct(void);
void	ft_putstr(char *str);
void	ft_display_map(char **mp, t_bsq *params);
void	ft_fill_map(t_bsq *p, int size, int row, int column);


int			get_next_line(int fd, char **line);
char		*ft_substr(char *s, int start, int len, int n_free);
int			free_return(char **s, int ret_value);
int			get_index(char *s, char c);
int			ft_strlen(char *s);
void		*ft_memcpy(void *dest, void *src, int n);
char		*ft_strjoin(char *s1, char *s2);

# define BUFFER_SIZE 4092
#endif
