#include "../includes/ft_bsq.h"

t_bsq        *ft_init_struct(void)
{
	t_bsq   *params;

	params = malloc(sizeof(t_bsq));
	if (!params)
		return (NULL);
	params->rd_ret = 1;
	params->line_size = 0;
	params->nb_lines = 0;
	params->fd = 0;
	params->error = 0;
	params->first_line = 0;
	params->map_col = 0;
	params->map_row = 0;
	params->save_index = 0;
	params->empty = '0';
	params->obstacle = '0';
	params->full = '0';
	params->map = NULL;
	params->buffer_size = 20;
	return (params);
}
