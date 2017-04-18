
#include "../includes/lem_in.h"

void	travel(t_main *g)
{
	char	**arr;

	while (g->end_nr != g->num_ants)
	{
		arr = links(g, g->start_room);
		int i = 0;
		while (arr[i])
		{
			//ft_putendl(arr[i]);
			while (ft_strcmp(g->rooms->name, arr[i]) != 0)
				g->rooms = g->rooms->next;
			if (g->rooms->in_room == 0)
			{
				g->rooms->in_room++;

		}
	}
}
