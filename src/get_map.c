
#include "../includes/lem_in.h"

char	*save_room(char *str)
{
	char	**line;
	char	*room;

	line = ft_strsplit(str, ' ');
	room = line[0];
	return (room);
}

t_rooms_list	*add_room(char *str, t_rooms_list *node, t_main *g)
{
	t_rooms_list	*head;

	if (node == NULL)
	{
		head = (t_rooms_list *)malloc(sizeof(t_rooms_list));
		node = head;
	}
	while (node->next != NULL)
		node = node->next;
	node->next = (t_rooms_list *)malloc(sizeof(t_rooms_list));
	node->name = save_room(str);
	g->num_rooms++;
	node = node->next;
	node->next = NULL;
	node = NULL;
	free(node);
	return (head);
}

t_links_list	*add_link(char *str, t_links_list *node, t_main *g)
{
	t_links_list	*head;

	if (node == NULL)
	{
		head = (t_links_list *)malloc(sizeof(t_links_list));
		node = head;
	}
	while (node->next != NULL)
		node = node->next;
	node->next = (t_links_list *)malloc(sizeof(t_links_list));
	node->link = str;
	node->arr = ft_strsplit(str, '-');
	g->num_links++;
	node = node->next;
	node->next = NULL;
	node = NULL;
	free(node);
	return (head);
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
	t_links_list	*links;

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
			rooms = add_room(node->str, rooms, g);
		else if (ft_strchr(node->str, '-') != NULL)
			links = add_link(node->str, links, g);
		node = node->next;
	}

	//sort_rooms(rooms, g);
	g->rooms = rooms;
	fill_start_room(g);
	g->ants = save_ants(g);
	g->ants = assign_rooms(g);
//	char	*test;
//	test = ft_strjoin3("sannie ", "sleep ", "sout");
//	ft_putendl(test);
	g->links = links;
	free(node);
	return (0);
}
