
#include "../includes/lem_in.h"
#include <stdio.h>  // REMOVE

t_rooms_list	*go_to_start(t_main *g, t_rooms_list *r)
{
	g->rooms = r;
	while (g->rooms->next)
	{
		if (ft_strcmp(g->rooms->name, g->start_room) == 0)
			break;
		g->rooms = g->rooms->next;
	}
	//	ft_putstr("GO TO START func: ");
	//	ft_putendl(g->rooms->name);
	return (g->rooms);
}

t_rooms_list	*go_to_room(t_main *g, char *str)
{
	//	t_rooms_list		*ph;

	//	ph = g->rooms;
	while (g->rooms->next)
	{
		if (ft_strcmp(g->rooms->name, str) == 0)
		{
			//g->rooms->in_room++;
			break;
		}
		g->rooms = g->rooms->next;
	}
	//	ft_putstr("WENT TO ROOM : ");
	//	ft_putendl(g->rooms->name);
	//	ft_putendl(" ");
	//	g->rooms = ph;
	return (g->rooms);
}

t_rooms_list	*move_from_to(t_main *g, t_rooms_list *r, char *from, char *to)
{
//	t_rooms_list	*r;

	g->rooms = r;
//	r = g->rooms;
//	ft_putstr("ROOM BEFORE FROM LOOP: ");
//	ft_putendl(g->rooms->name);
	while (g->rooms->next) // CONCIDER USING go_to_room
	{
		if (ft_strcmp(g->rooms->name, from) == 0 && 
				ft_strcmp(g->rooms->name, g->end_room) != 0)
		{
			g->rooms->in_room--;
			break;
		}
		g->rooms = g->rooms->next;
	}
	g->rooms = r;
//	ft_putstr("ROOM BEFORE TO LOOP: ");
//	ft_putendl(g->rooms->name);
	while (g->rooms->next) // CONCIDER USING go_to_room
	{
		ft_putstr("CHECKING ROOM NR: ");
		ft_putendl(g->rooms->name);
		if (ft_strcmp(g->rooms->name, to) == 0)
		{
			ft_putstr("TO: ");
			ft_putendl(to);
			g->rooms->in_room++;
			//ft_putstr("MOVE FROM TO - ROOM AND NUM ANTS: ");
			//ft_putendl(g->rooms->name);
			//ft_putendl(ft_itoa(g->rooms->in_room));
			break;
		}
		g->rooms = g->rooms->next;
	}
	return (r);
}

int	ants_in_room(t_main *g, t_rooms_list *r, char *str)
{
	int		ret;
	//t_rooms_list	*r;

	g->rooms = r;
	//ft_putstr("CURRENT ROOM BEFORE FUNC: ");
	//ft_putendl(g->rooms->name);
	while (g->rooms->next) // CONCIDER go_to_room
	{
		if (ft_strcmp(g->rooms->name, str) == 0)
		{
			ret = g->rooms->in_room;
			//g->rooms = r;
			break;
		}
		g->rooms = g->rooms->next;
	}
	g->rooms = r;
	//ft_putstr("CURRENT ROOM AFTER FUNC: ");
	//ft_putendl(g->rooms->name);
	return (ret);
}

void	travel(t_main *g)
{
	char		**arr;
//	char		*tmp;
	t_rooms_list	*r;
	//t_ants_list	*a;

	r = g->rooms;
	ft_putstr("### END_ROOM: ");
	ft_putendl(g->end_room);
	int test = ants_in_room(g, r, g->end_room);
	ft_putendl(ft_itoa(test));
	while ((ants_in_room(g, r, g->end_room) != g->num_ants))
//	while ((ants_in_room(g, r, g->start_room) != 0))
	{
		ft_putstr("### END_ROOM: ");
		test = ants_in_room(g, r, g->end_room);
		ft_putendl(ft_itoa(test));
		while (g->rooms->next)
		{
			ft_putendl("\nSTART OF LOOP");
			ft_putstr("ROOM NAME: ");
			ft_putendl(g->rooms->name);
			ft_putstr("NUM ANTS: ");
			ft_putendl(ft_itoa(g->rooms->in_room));
			if (g->rooms->in_room != 0)
			{
				arr = links(g, g->rooms->name);
				//tmp = g->rooms->name;
				while (*arr)
				{
					ft_putstr("TESTING LINK: ");
					ft_putendl(*arr);
					if ((ants_in_room(g, g->rooms, *arr)) == 0 || 
							ft_strcmp(*arr, g->end_room) == 0)
					{
						g->rooms = move_from_to(g, r, g->rooms->name, *arr);
						ft_putendl("GREAT SUCCESS!");
					}
					arr++;
				}
				//g->rooms = move_from_to(g, r,
			}
			ft_putendl("END OF LOOP");
			//ft_putstr("ROOM NAME: ");
//			ft_putendl(g->rooms->name);
			ft_putstr("NUM ANTS: ");
			ft_putendl(ft_itoa(g->rooms->in_room));
//			ft_putendl(ft_itoa(ants_in_room(g, g->rooms, g->rooms->name)));
			g->rooms = g->rooms->next;
		}
		g->rooms = r;
	}
}
