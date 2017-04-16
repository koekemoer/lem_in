
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

/*void		test(t_main *g)
{*/

