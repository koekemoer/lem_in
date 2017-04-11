
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
}

int	main()
{
	t_main		g;
	//int		test;
	//t_input_list	i;

	g.data = save_input(&g);
	init(&g);

	//ft_putendl("SAVE INPUT DONE\nMAIN func");
	/*while (g.data->next)
	{
		ft_putendl(g.data->str);
		g.data = g.data->next;
	}*/
	//ft_putendl("SAVE_INPUT WORKS");

	//ft_putendl("START OF GET_MAPS");
	if (get_map(&g)){};
	printf("NUMBER OF ANTS: %d\n", g.num_ants);
	printf("NUMBER OF ROOMS: %d\n", g.num_rooms);
	//ft_putendl("END OF GET_MAPS in MAIN");
	return (0);
}
