#include "../includes/lem_in.h"

t_ants_list		*save_ants(t_main *g)
{
	t_ants_list		*head;
	t_ants_list		*node;
	int				i;

	head = NULL;
	i = 1;
	while (i <= g->num_ants)
	{
		if (head == NULL)
		{
			head = (t_ants_list *)malloc(sizeof(t_ants_list));
			node = head;
		}
		node->name = ft_strjoin("L", ft_itoa(i));
		//ft_putendl(node->name);
		node->next = (t_ants_list *)malloc(sizeof(t_ants_list));
		if (node->name == NULL || ft_strcmp("\0", node->name) == 0)
			error();
		i++;
		node = node->next;
	}
	//ft_putchar('\n');
	node->next = NULL;
	node = NULL;
	free(node);
	return (head);
}

t_ants_list		*assign_rooms(t_main *g)
{
	t_ants_list	*head;
	t_rooms_list	*tmp;
	int		i;

	tmp = g->rooms;
	head = g->ants;
	while (g->rooms->next)
	{
		ft_putstr("ASSIGN ROOMS IS AT: ");
		ft_putendl(g->rooms->name);
		ft_putstr("ANTS IN ROOM: ");
		ft_putendl(ft_itoa(g->rooms->in_room));
		i = g->rooms->in_room;
		while (i != 0)
		{
			while (g->ants->next)
			{
				g->ants->room = g->rooms->name;
				ft_putstr("WILLIE: ");
				ft_putstr(g->ants->name);
				ft_putstr("-");
				ft_putendl(g->ants->room);
				g->ants = g->ants->next;
			}
			i--;
		}
		g->ants = head;
		g->rooms = g->rooms->next;
	}
	//a = head;
	g->rooms = tmp;
	return (head);
}

/* NOT IN WORKING CONDITION */
t_visited	*add_visited(t_visited *node, char *room)
{
	t_visited	*head;

	if (node == NULL)
	{
		head = (t_visited *)malloc(sizeof(t_visited));
		node = head;
	}
	ft_debug("ADD_VISITED: AFTER IF", "1");
	while (node->next != NULL)
		node = node->next;
	ft_debug("ADD_VISITED: AFTER WHILE", "2");
	node->next = (t_visited *)malloc(sizeof(t_visited));
	ft_debug("ADD_VISITED: AFTER MALLOC", "3");
	node->room = room;
	ft_debug("ADD_VISITED: AFTER WHATEVER", "4");
	node = node->next;
	node->next = NULL;
	node = NULL;
	free(node);
	return (head);
}





