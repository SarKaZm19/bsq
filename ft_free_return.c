#include "ft_bsq.h"

t_bsq	*ft_free_return(t_bsq *params, char *str)
{
	if (str)
		free(str);
	str = NULL;
	params->rd_ret = 0;
	params->error = 1;
	write(1, "map error\n", 10);
	return (params);
}
