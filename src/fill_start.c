/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoekemo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 11:11:57 by lkoekemo          #+#    #+#             */
/*   Updated: 2017/05/18 11:12:01 by lkoekemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		fill_start_room(t_main *g/*, t_rooms_list *r*/)
{
	t_rooms_list		*tmp;

	tmp = g->rooms;
	while (g->rooms->next)
	{
		if (ft_strcmp(g->rooms->name, g->start_room) == 0)
			g->rooms->in_room = g->num_ants;
		ft_putstr("ROOM NAME: ");
		ft_putendl(g->rooms->name);
		ft_putstr("ANTS IN ROOM: ");
		ft_putendl(ft_itoa(g->rooms->in_room));
		g->rooms = g->rooms->next;
	}
	g->rooms = tmp;
//	ft_putstr("AFTER FILL START: ");
//	ft_putendl(g->rooms->name);
}

char		*get_link(t_main *g, char *str)
{
//	t_links_list	*head;

//	head = g->links;

	char	*ret = NULL;

	while (g->links->next && ret == NULL)
	{
		if (ft_strcmp(str, g->links->arr[0]) == 0)
			ret = g->links->arr[1];
		if (ft_strcmp(str, g->links->arr[1]) == 0)
			ret = g->links->arr[0];
	//	if (ret != NULL)
	//		return (ret);
		//ft_putstr(g->links->arr[0]);
		//ft_putstr("<->");
		//ft_putendl(g->links->arr[1]);
		g->links = g->links->next;
	}
//	g->links = head; // RESET LIST TO START
	return (ret);
}

char		**links(t_main *g, char *test)
{
	char		**arr;
	char		*tmp;
	t_links_list	*head;
	int		i;

	tmp = NULL;
	i = 0;
	head = g->links;
	while ((tmp = get_link(g, test)))
		i++;
	g->links = head;
	if (!(arr = (char **)malloc(sizeof(*arr) * i + 1)))
		return NULL;
	i = 0;
	while ((tmp = get_link(g, test)))
	{
		arr[i] = tmp;
		i++;
	}
	arr[i] = 0;
	g->links = head;
	return (arr);
}

/* 'N FUNCTION WAT SEKER MAAK DAT DIE ANT NA DIE END ROOM TOE SKUIF AS HY BESTAAN IN DIE LINK */
