
#include "../includes/lem_in.h"
#include <stdio.h>  // REMOVE

t_rooms_list	*go_to_start(t_main *g)
{
	while (g->rooms->next)
	{
		if (ft_strcmp(g->rooms->name, g->start_room) == 0)
			break;
		g->rooms = g->rooms->next;
	}
	ft_putstr("GO TO START func: ");
	ft_putendl(g->rooms->name);
	return (g->rooms);
}


void	travel(t_main *g)
{
	char		**arr;
	int		i;
	t_rooms_list	*head;
	t_rooms_list	*tmp;
//	t_main		*tmp;

	head = g->rooms;
	tmp = g->rooms;
//	tmp = g;
//	while (g->nr_end != g->num_ants)
//	{
//		ft_putendl("1");
		//g->rooms = head;
		g->rooms = go_to_start(g);
		while (g->rooms->next)
		{
			ft_putendl("2");
//			printf("PREV ROOM: %s\n", tmp->name);
			i = 0;
			arr = links(g, g->rooms->name);
			while (arr[i])
			{
				ft_putendl("3");
				printf("CURRENT ROOM: %s\n", g->rooms->name);
				printf("PREV ROOM: %s\n", tmp->name);
				printf("ARRAY[%d]: %s\n", i, arr[i]);
				if (g->rooms->in_room == 0 && 
						ft_strcmp(arr[i], tmp->name) != 0)
				{
					ft_putendl("4");
					g->rooms->in_room++;
					tmp->in_room--;
					printf("ROOM NAME: %s\n", g->rooms->name);
					printf("ANTS IN ROOM: %d\n", g->rooms->in_room);
					printf("PREVIOUS ROOM: %s\n", tmp->name);
					printf("ANTS IN ROOM: %d\n", tmp->in_room);
				}
				i++;
			}
			//free_args(arr);
			tmp = g->rooms;
			g->rooms = g->rooms->next;
//			head = head->next;
		}
		g->rooms = head;
//	}
}
