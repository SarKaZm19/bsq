#include "ft_bsq.h"

char	*ft_strjoin(char *save, char *buff)
{
	char    *joined;
	int     len_save;
	int     len_buff;
	int     i;
	int     j;

	if (!save && !buff)
	{
		printf("hello\n");
		return (NULL);
	}
	len_save = ft_strlen(save);
	len_buff = ft_strlen(buff);
	printf("lenbuff = %d\nlensave=%d\n", len_buff, len_save);
	joined = malloc(sizeof(char) * (len_save + len_buff + 1));
	if (!joined)
		return (NULL);
	i = 0;
	while (i < len_save)
		i++;
	j = -1;
	while (++j < len_buff)
		joined[i + j] = buff[j];
	joined[i + j] = '\0';
	free(save);
	return (joined);
}
