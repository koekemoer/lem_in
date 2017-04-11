
#include "../includes/lem_in.h"

char	*save_room(char *str/*, t_main *g*/)
{
	char	**line;
	char	*room;

	line = ft_strsplit(str, ' ');
	room = line[0];
	//g->num_rooms++;
	//ft_putstr("ROOM NAME: ");
	//ft_putendl(room);
	return (room);
}

void	add_room(char *str, t_rooms_list *r)
{
	//t_rooms_list	*head;
	//t_rooms_list	*r;

	if (r == NULL)
	{
		r = (t_rooms_list *)malloc(sizeof(t_rooms_list));
		r->name = save_room(str);
		r->next = NULL;
	//	ft_putendl(r->name);
	}
//	node = head;
	while (r->next)
		r = r->next;
	r->next = (t_rooms_list *)malloc(sizeof(t_rooms_list));
	r = r->next;
	r->name = save_room(str);
	ft_putendl(r->name);
	r->next = NULL;
}

void		get_start_end(char* str, t_main *g)
{
	if (g->start_flag == 1)
	{
		g->start_room = save_room(str);
		g->start_flag = 0;
	}
	else if (g->end_flag == 1)
	{
		g->end_room = save_room(str);
		g->end_flag = 0;
	}
	else if (ft_strcmp("##start", str) == 0)
		g->start_flag = 1;
	else if (ft_strcmp("##end", str) == 0)
		g->end_flag = 1;
}


int		get_map(t_main *g)
{
	t_input_list	*node;
	t_rooms_list	*rooms;

	node = g->data;
	rooms = NULL;
	while (node->next)
	{
		get_start_end(node->str, g);
		// DETERMINE NUMBER OF ANTS
		if (g->num_ants == 0)
			g->num_ants = ft_atoi(node->str); // HAVE TO DO ERROR CHECK
		// DETERMINE NUMBER OF ROOMS
		else if (ft_strchr(node->str, ' ') != NULL)
			//g->num_rooms++;		
			add_room(node->str, rooms);
		node = node->next;
	}
	free(node);
	return (0);
}
