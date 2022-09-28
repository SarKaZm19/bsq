#include "../includes/ft_bsq.h"

/*t_bsq	*ft_free_exit(t_bsq *params)
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
}*/

int	ft_bsq_atoi(t_bsq *params, char *save, int len)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (i < len && save[i] >= '0' && save[i] <= '9')
	{
		if (save[i] != params->empty)
			nb = (nb * 10) + (save[i] - '0');
		i++;
	}
	//printf("bsqatoi1\n");
	//printf("i = %d, len = %d, nb = %d\n", i, len, nb);
	if (i != len)
		return(1);
	if (nb == 0 || nb > 2147483647)
	{
		params->nb_lines = 0;
		return (1);
	}
	//printf("bsqatoi2\n");
	params->nb_lines = nb;
	return (0);
}

int	ft_get_first_line(t_bsq *params, char *args)
{
	int	len;

	len = ft_has_nl(args, 0, 0);
	//printf("len = %d\n", len);
	if (len < 4)
		return (1);
	params->full = args[len - 1];
	params->obstacle = args[len - 2];
	params->empty = args[len - 3];
	//printf("empty = %c, obstacle = %c, full = %c\n", params->empty, params->obstacle, params->full);
	if (params->full == params->obstacle || params->full == params->empty
		|| params->obstacle == params->empty)
		return (1); //verif non printable
	params->error = ft_bsq_atoi(params, args, len - 3);
	if (params->error == 1)
		return (1);
	printf("params->nb_lines = %d\n", params->nb_lines);
	params->map = malloc(sizeof(char*) * (params->nb_lines + 1));
	if (!(params->map))
		return (1);
	params->map[params->nb_lines] = "\0";
	params->first_line = 1;
	params->save_index = len;
	return (0);
}

/*char	*ft_linedup(t_bsq *params, char *save, int len)
{
	char	*line;
	int 	index;
	int		save_i;

	save_i = params->save_index;
	//printf("len = %d, save_i + 1 = %d\n", len, save_i + 1);
	line = malloc(sizeof(char) * (len - save_i + 1));
	if (!line)
		ft_free_exit(params, save);
	index = 0;
	while (save_i < len)
	{
		if (save[save_i] == params->empty || save[save_i] == params->obstacle)
			line[index] = save [save_i];
		else
		{
			free(line);
			line = NULL;
			params->error = 1;
			return (line);
		}
		index++;
		save_i++;
	}
	line[index] = '\0';
	//printf("save_i = %d\n", save_i);
	printf(":%s:\n", line);
	params->save_index = save_i;
	return (line);
}

int	ft_get_lines(t_bsq *params, char *save)
{
	int	max;

	//printf("save=%c, index = %d\n", save[params->save_index], params->save_index);
	if  (save[params->save_index] == '\n' && save[params->save_index + 1] == '\0')
	{
		params->map[params->map_row] = NULL;
		free(save);
		return (0);
	}
	while (save[params->save_index])
	{
		params->save_index += 1;
		max = ft_has_nl(save, 0, params->save_index);
		if (save[max] == '\0')
			params->rd_ret = 0;
		printf("params->line_size = %d, max = %d, params->save_index = %d\n", params->line_size, max, params->save_index);
		if (params->line_size == 0 || params->line_size == max - params->save_index)
			params->line_size = max - params->save_index;
		else if (params->save_index == max)
			return (0);
		else
			return (1);
		printf("params->map_row = %d\n", params->map_row); // segfault ici
		params->map[params->map_row] = ft_linedup(params, save, max);
		params->map_row += 1;
		//printf("i = %d\n", params->save_index);

	}
	return (0);
}

t_bsq	*ft_build_map(t_bsq *params, char *save)
{
	if (params->first_line == 0)
	{
		params->error = ft_get_first_line(params, save);
		if (params->error == 1)
		{
			params->rd_ret = 0;
			return (params);
		}
	}
	if (params->first_line == 1)
	{
		params->error = ft_get_lines(params, save);
		if (params->error == 1)
		{
			params->rd_ret = 0;
			return (params);
		}
	}	
	return (params);
}*/
