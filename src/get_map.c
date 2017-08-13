/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerasmus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 17:17:31 by jerasmus          #+#    #+#             */
/*   Updated: 2017/05/28 14:10:41 by lkoekemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char				*save_room(char *str)
{
	char			*room;
	size_t			i;

	i = 0;
	while (str[i] != ' ')
		i++;
	room = (char *)ft_memalloc(sizeof(char) * (i + 1));
	ft_strncpy(room, str, i);
	return (room);
}

t_rooms				*add_room(char *str, t_rooms *node, t_main *g)
{
	t_rooms			*head;

	head = node;
	if (node == NULL)
	{
		head = (t_rooms *)ft_memalloc(sizeof(t_rooms));
		node = head;
	}
	while (node->next != NULL)
		node = node->next;
	node->next = (t_rooms *)ft_memalloc(sizeof(t_rooms));
	node->name = save_room(str);
    if (str[0] != '#')
	    ft_putendl(str);
	g->num_rooms++;
	return (head);
}

t_links				*add_link(char *str, t_links *node, t_main *g)
{
	t_links			*head;

	head = node;
	if (node == NULL)
	{
		head = (t_links *)ft_memalloc(sizeof(t_links));
		node = head;
	}
	while (node->next != NULL)
		node = node->next;
	node->next = (t_links *)ft_memalloc(sizeof(t_links));
	node->link = str;
	node->arr = ft_strsplit(str, '-');
    if (str[0] != '#')
        print_arr(node->arr);
	g->num_links++;
	return (head);
}

void				get_start_end(char *str, t_main *g)
{
	if (g->start_flag == 1)
	{
		g->start_room = save_room(str);
		g->start_flag = -1;
	}
	else if (g->end_flag == 1)
	{
		g->end_room = save_room(str);
		g->end_flag = -1;
	}
	else if (ft_strcmp("##start", str) == 0 && g->start_flag != -1)
    {
        g->start_flag = 1;
        ft_putendl(str);
    }
	else if (ft_strcmp("##end", str) == 0 && g->end_flag != -1)
    {
        g->end_flag = 1;
        ft_putendl(str);
    }
}

int					get_map(t_main *g)
{
	t_input			*node;
	t_rooms			*rooms;
	t_links			*links;

	node = g->data;
	rooms = NULL;
	links = NULL;
	while (node->next)
	{
		get_start_end(node->str, g);
		print_map(g);
		if (ft_strchr(node->str, ' ') != NULL)
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
	return (0);
}
