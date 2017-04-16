#include "libft.h"

void	free_args(char **arr)
{
	int		i;

	i = 0;
	if (arr == NULL)
		return ;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	if (arr != NULL)
		free(arr);
}
