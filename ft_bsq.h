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
	char    **map;
}               t_bsq;

t_bsq	*ft_build_map(t_bsq *params, char *save);
int	ft_has_nl(char *str, int trigger, int index);
int	ft_strlen(char *str);
char	*ft_strjoin(char *save, char *buff);
t_bsq	*ft_free_return(t_bsq *params, char *str);
t_bsq	*ft_init_struct(void);



#define BUFFER_SIZE 4096

#endif