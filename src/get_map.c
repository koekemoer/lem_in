
#include "../includes/lem_in.h"

void	save_room(char *str)
{
	char	**line;
	char	*room;

	line = ft_strsplit(str, ' ');
	room = line[0];
	ft_putstr("ROOM NAME: ");
	ft_putendl(room);
}

int	get_map(t_main *g)
{
	t_input_list	*node;

	node = g->data;
//	ft_putendl("BEFORE LOOP");
	while (node->next)
	{
		// DETERMINE NUMBER OF ANTS
		if (g->num_ants == 0)
			g->num_ants = ft_atoi(node->str); // HAVE TO DO ERROR CHECK
		// DETERMINE NUMBER OF ROOMS
		else if (ft_strchr(node->str, ' ') != NULL)
		{
			save_room(node->str);
			g->num_rooms++;
		}
		node = node->next;
	}
//	ft_putendl("END OF LOOP");
	free(node);
	return (0);
}
