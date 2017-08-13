/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerasmus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 17:16:49 by jerasmus          #+#    #+#             */
/*   Updated: 2017/05/25 17:21:12 by jerasmus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_ants			*save_ants(t_main *g)
{
	t_ants		*head;
	t_ants		*node;
	int			i;
	char		*tmp;

	head = NULL;
	i = 1;
	while (i <= g->num_ants)
	{
		if (head == NULL)
		{
			head = (t_ants *)ft_memalloc(sizeof(t_ants));
			node = head;
		}
		tmp = ft_itoa(i);
		node->name = ft_strjoin("L", tmp);
		free(tmp);
		node->next = (t_ants *)ft_memalloc(sizeof(t_ants));
		if (node->name == NULL || ft_strcmp("\0", node->name) == 0)
			error();
		i++;
		node = node->next;
	}
	node->next = NULL;
	return (head);
}

t_ants			*assign_rooms(t_main *g)
{
	t_ants		*head;
	t_rooms		*tmp;
	int			i;

	tmp = g->rooms;
	head = g->ants;
	while (g->rooms->next)
	{
		i = g->rooms->in_room;
		while (i != 0)
		{
			while (g->ants->next)
			{
				g->ants->room = g->rooms->name;
				g->ants->last = NULL;
				g->ants = g->ants->next;
			}
			i--;
		}
		g->ants = head;
		g->rooms = g->rooms->next;
	}
	g->rooms = tmp;
	return (head);
}
