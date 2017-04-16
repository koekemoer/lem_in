
#include "../includes/lem_in.h"
#include <stdio.h> //REMOVE

void	error()
{
	ft_putendl("ERROR BOETIE!");
	exit(1);
}

void	init(t_main *g)
{
	g->num_ants = 0;
	g->num_rooms = 0;
	g->num_links = 0;
	g->start_flag = 0;
	g->end_flag = 0;
}

int	main()
{
	t_main		g;
	//t_rooms_list	*r;
	//int		test;
	//t_input_list	i;

	g.data = save_input(&g);
	init(&g);
	//r = g.rooms;

	//ft_putendl("SAVE INPUT DONE\nMAIN func");
	/*while (g.data->next)
	{
		ft_putendl(g.data->str);
		g.data = g.data->next;
	}*/
	//ft_putendl("SAVE_INPUT WORKS");

	//ft_putendl("START OF GET_MAPS");
	//if (get_map(&g))
	get_map(&g);	
	//{
		printf("\nNUMBER OF ANTS: %d\n", g.num_ants);
		printf("NUMBER OF ROOMS: %d\n", g.num_rooms);
		printf("NUMBER OF LINKS: %d\n", g.num_links);
		printf("START-ROOM: %s\n", g.start_room);
		printf("END-ROOM: %s\n\n", g.end_room);
	//}
	t_rooms_list *r = g.rooms;
//	fill_start_room(&g/*, g.rooms*/);
//	g.rooms = r;
	printf("\nROOMS:\n");
	while (g.rooms->next)
	{
		ft_putendl(g.rooms->name);
		g.rooms = g.rooms->next;
	}
	printf("LINKS:\n");
	while (g.links->next)
	{
		ft_putendl(g.links->link);
		g.links = g.links->next;
	}
	ft_putchar('\n');
	g.rooms = r;
//	fill_start_room(&g);
	return (0);
}
