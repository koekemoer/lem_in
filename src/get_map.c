/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoekemo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 14:31:31 by lkoekemo          #+#    #+#             */
/*   Updated: 2017/05/18 11:19:45 by lkoekemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char	*save_room(char *str)
{
	char	**line;
	char	*room;

	line = ft_strsplit(str, ' ');
	room = line[0]; // strdup dalk en free
	return (room);
}

t_rooms	*add_room(char *str, t_rooms *node, t_main *g)
{
	t_rooms	*head;

	head = node;
	if (node == NULL)
	{
		head = (t_rooms *)malloc(sizeof(t_rooms));
		node = head;
	}
	while (node->next != NULL)
		node = node->next;
	node->next = (t_rooms *)malloc(sizeof(t_rooms));
	node->name = save_room(str);
	g->num_rooms++;
	node = node->next;
	node->next = NULL;
	node = NULL;
	free(node);
	return (head);
}

t_links	*add_link(char *str, t_links *node, t_main *g)
{
	t_links	*head;

	head = node;
	if (node == NULL)
	{
		head = (t_links *)malloc(sizeof(t_links));
		node = head;
	}
	while (node->next != NULL)
		node = node->next;
	node->next = (t_links *)malloc(sizeof(t_links));
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
	t_rooms			*rooms;
	t_links			*links;

	node = g->data;
	rooms = NULL;
	links = NULL;
	while (node->next)
	{
		get_start_end(node->str, g);
		if (g->num_ants == 0)
			g->num_ants = ft_atoi(node->str);
		else if (ft_strchr(node->str, ' ') != NULL)
			//g->num_rooms++;		
			rooms = add_room(node->str, rooms, g);
		else if (ft_strchr(node->str, '-') != NULL)
			links = add_link(node->str, links, g);
		node = node->next;
	}
	g->rooms = rooms;
	fill_start_room(g);
	g->ants = save_ants(g);
	g->ants = assign_rooms(g);
	g->links = links;
	free(node);
	return (0);
}
