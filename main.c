#include "ft_bsq.h"


int	ft_free_params(t_bsq *params)
{
	int	i;

	i = 0;
	while (i < params->map_row)
	{
		if (params->map[i])
			free(params->map[i]);
		i++;
	}
	if (params->map)
		free(params->map);
	free(params);
	return (0);
}

int	ft_has_nl(char *save, int trigger, int i)
{
	if (!save)
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	if (trigger == 1)
	{
		if (save[i] == '\n')
			return (1);
		return (0);
	}
	return (i);
}

t_bsq	*ft_get_map(t_bsq *params)
{
	char		*buff;
	static char	*save;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (params->fd < 0 || params->fd > FOPEN_MAX || !BUFFER_SIZE || !buff) // OPEN_MAX = MAcro, fd peut pas être sup a 1023 
				      														// (nb de fichier ouvert en meme temps)
		return (ft_free_return(params, 0));
	printf("Hello loop");
	while (!(ft_has_nl(save, 1, 0)) && params->rd_ret != 0)
	{
		params->rd_ret = read(params->fd, buff, BUFFER_SIZE);
		printf("ret = %d\n", params->rd_ret);
		if (params->rd_ret == -1)
			return (ft_free_return(params, buff));
		buff[params->rd_ret] = '\0';
		save = ft_strjoin(save, buff);
		if (!save)
			return (ft_free_return(params, buff));
	}
	free(buff);
	params = ft_build_map(params, save);
	if (params->error == 1)
		return (params);
	if (save)
		free(save);
	params->rd_ret = 0;
	/*if (params->rd_ret != 0 && save)
		save = ft_get_save(save, ft_has_nl(save, 0, 0), params);*/
	return (params);
}

int	main(int ac, char **av)
{
	int	i;
	t_bsq	*params;
	int	k;
	if (ac == 1)
	{
		//read_stdin
		printf("No args; reqd stdin");
	}
		//read stdin
	else if (ac >= 2)
	{
		i = 1;
		while (i < ac) // chaque fichier passé en args
		{
			params = ft_init_struct();
			if (!params)
				return (1);
			params->fd = open(av[i], O_RDONLY);
			printf("fd = %d\n", params->fd);
			while (params->rd_ret != 0)
			{
				params = ft_get_map(params);
			} // si params->ret revient à 0, fin de fichier en cours
			k = 0;
			printf("params->map_row = %d\n", params->map_row);
			while (k < params->map_row)
			{
				printf(":%s:\n", params->map[k]);
				k++;
			}
			if (params->error == 1)
				printf("map error\n");
			
			
			ft_free_params(params); // free, tab, close
			i++;
		}
	}
	else
	{
		printf("wtf\n");
	}
	return (0);
}
