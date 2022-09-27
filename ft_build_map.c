#include "ft_bsq.h"

t_bsq	*ft_free_exit(t_bsq *params, char *save)
{
	int	row;

	if (save)
		free(save);
	if (params)
	{
		row = 0;
		while (params->map[row])
			free(params->map[row++]);
		free(params->map);
		free(params);
	}
	params = NULL;
	close(params->fd);
	printf("malloc error\n");
	exit(1);
	return (params);
}

int	ft_bsq_atoi(t_bsq *params, char *save, int len)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	nb = 0;
	while (i < len && save[i] >= '0' && save[i] <= '9')
	{
		j = i + 1;
		while (save[j] != params->empty)
		{
			if (save[i] == save[j])
				return(1);
			j++;
		}
		nb = (nb * 10) + (save[i] - '0');
		i++;
	}
	printf("bsqatoi1\n");
	printf("i = %d, len = %d, nb = %d\n", i, len, nb);
	if (i != len)
		return(1);
	if (nb == 0 || nb > 2147483647)
	{
		params->nb_lines = 0;
		return (1);
	}
	printf("bsqatoi2\n");
	params->nb_lines = nb;
	return (0);
}

int	ft_get_first_line(t_bsq *params, char *save)
{
	int	len;

	len = ft_has_nl(save, 0, 0);
	printf("len = %d\n", len);
	if (len < 4)
		return (1);
	params->full = save[len - 2];
	params->obstacle = save[len - 3];
	params->empty = save[len - 4];
	printf("empty = %c, obstacle = %c, full = %c\n", params->empty, params->obstacle, params->full);
	if (params->full == params->obstacle || params->full == params->empty
		|| params->obstacle == params->empty)
		return (1);
	params->error = ft_bsq_atoi(params, save, len - 4);
	if (params->error == 1)
		return (1);
	printf("params->nb_lines = %d\n", params->nb_lines);
	params->map = malloc(sizeof(char) * (params->nb_lines + 1));
	if (!(params->map))
		return (1);
	params->line_size = len;
	params->first_line = 1;
	return (0);
}

char	*ft_linedup(t_bsq *params, char *save, int *i, int len)
{
	char	*line;
	int 	index;

	line = malloc(sizeof(char) * (len - *i + 1));
	if (!line)
		ft_free_exit(params, save);
	index = 0;
	while (save[*i] != '\n' && save[*i])
	{
		line[index] = save [*i];
		index++;
		*i += 1;
	}
	line[index] = '\0';
	printf("*i = %d\n", *i);
	printf(":%s:\n", line);
	printf("%s\n", save);
	return (line);
}

int	ft_get_lines(t_bsq *params, char *save)
{
	int	i;
	//int	j;
	int	max;

	i = 0;
	printf("save=%s\n", save);
	while (save[i])
	{
		//j = 0;
		max = ft_has_nl(save, 0, i);
		printf("params->line_size = %d, max = %d, i = %d\n", params->line_size, max, i);
		if (params->line_size != 0 && (max - i != params->line_size))
			return(1);	
		params->line_size = max - i;
		printf("params->map_row = %d\n", params->map_row); // segfault ici
		params->map[params->map_row] = ft_linedup(params, save, &i, max);
		printf("i = %d\n", i);
		params->map_row++;
		i++;
	}
	params->rd_ret = 0;
	free(save);
	return (0);
}

t_bsq	*ft_build_map(t_bsq *params, char *save)
{
	if (params->first_line == 0)
	{
		params->error = ft_get_first_line(params, save);
		if (params->error == 1)
			return (params);
	}
	if (params->first_line == 1)
	{
		params->error = ft_get_lines(params, save);
		if (params->error == 1)
			return (params);
	}
	//printf("params[k] = %s\n", *(params->map));
	//condition d'arret sur nb_lnes == 0 et/ou firsT_line = 0
	
	return (params);
}
