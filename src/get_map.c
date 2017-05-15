/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoekemo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 14:31:31 by lkoekemo          #+#    #+#             */
/*   Updated: 2017/05/15 14:54:41 by lkoekemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	ft_putendl("add_room");

	head = node;
	if (node == NULL)
	{
		head = (t_rooms_list *)malloc(sizeof(t_rooms_list));
		node = head;
	}
//	ft_putendl("add_room 1.25");
	while (node->next != NULL)
	{
//		ft_debug("node_room", node->name != NULL ? node->name : "NUL");
		node = node->next;
	}
//	ft_putendl("add_room 1.5");
//	if (node->next == NULL)
	node->next = (t_rooms_list *)malloc(sizeof(t_rooms_list));
	node->name = save_room(str);
//	ft_putendl("add_room 1.75");
//	ft_debug("ROOM SAVED", node->name);
//	ft_putendl("add_room 2");
	g->num_rooms++;
	node = node->next;
	node->next = NULL;
	node = NULL;
	free(node);
//	ft_putendl("add_room 3");
	return (head);
}

t_links_list	*add_link(char *str, t_links_list *node, t_main *g)
{
	t_links_list	*head;
	ft_putendl("add_link");

	head = node;
	if (node == NULL)
	{
		ft_putendl("123");
		head = (t_links_list *)malloc(sizeof(t_links_list));
		node = head;
	}
	ft_putendl("456");
	while (node->next != NULL)
		node = node->next;
	ft_putendl("789");
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
	links = NULL;
	ft_putendl("get_map");
	while (node->next)
	{
		ft_putendl("inside while");
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
	ft_putendl("outside while");

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
