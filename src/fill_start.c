
#include "../includes/lem_in.h"

void		fill_start_room(t_main *g/*, t_rooms_list *r*/)
{
	t_rooms_list		*tmp;

	tmp = g->rooms;
	while (g->rooms->next)
	{
		if (ft_strcmp(g->rooms->name, g->start_room) == 0)
			g->rooms->in_room = g->num_ants;
//		ft_putstr("ROOM NAME: ");
//		ft_putendl(g->rooms->name);
//		ft_putstr("ANTS IN ROOM: ");
//		ft_putendl(ft_itoa(g->rooms->in_room));
		g->rooms = g->rooms->next;
	}
	g->rooms = tmp;
}

char		*get_link(t_main *g, char *str)
{
	char		**link_arr;
	t_links_list	*head;

	head = g->links;
	while (g->links->next)
	{
		link_arr = ft_strsplit(g->links->link, '-');
		if (ft_strcmp(link_arr[0], str) == 0)
		{
			g->links = head;
			return (link_arr[1]);
		}
		else if (ft_strcmp(link_arr[1], str) == 0)
		{
			g->links = head;
			return (link_arr[0]);
		}
		g->links = g->links->next;
		free_args(link_arr);
	}
	g->links = head;
	return (NULL);
}

