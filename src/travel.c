
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
	g->rooms = r;
	while (g->rooms->next) // CONCIDER USING go_to_room
	{
		if (ft_strcmp(g->rooms->name, from) == 0)
		{
			g->rooms->in_room--;
			break;
		}
		g->rooms = g->rooms->next;
	}
	g->rooms = r;
	while (g->rooms->next) // CONCIDER USING go_to_room
	{
		if (ft_strcmp(g->rooms->name, to) == 0)
		{
			g->rooms->in_room++;
			break;
		}
		g->rooms = g->rooms->next;
	}
	return (r);
}

int	ants_in_room(t_main *g, char *str)
{
	int		ret;
	t_rooms_list	*r;

	r = g->rooms;
	while (g->rooms->next) // CONCIDER go_to_room
	{
		if (ft_strcmp(g->rooms->name, str) == 0)
		{
			ret = g->rooms->in_room;
			break;
		}
		g->rooms = g->rooms->next;
	}
	g->rooms = r;
	return (ret);
}

void	travel(t_main *g)
{
	char		**arr;
//	char		*tmp;
//	int		i;
	t_rooms_list	*r;
	//t_ants_list	*a;

	r = g->rooms;
	//a = g->ants;
	while (g->rooms->next)
	{
		if (g->rooms->in_room != 0)
		{
			arr = links(g, g->rooms->name);
//			tmp = g->rooms->name;
			while (*arr)
			{
				if ((ants_in_room(g, *arr)) == 0)
					ft_putendl("GREAT SUCCESS!");
				arr++;
			}
			//g->rooms = move_from_to(g, r,
		}
		g->rooms = g->rooms->next;
	}
	g->rooms = r;
}
