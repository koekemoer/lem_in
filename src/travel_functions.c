/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   travel_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoekemo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 11:14:42 by lkoekemo          #+#    #+#             */
/*   Updated: 2017/05/18 14:50:59 by lkoekemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			check_for_end(t_main *g, char **arr)
{
	while (*arr)
	{
		if (ft_strcmp(*arr, g->end_room) == 0)
			return (1);
		arr++;
	}
	return (0);
}

void		test_end(t_main *g, t_ants *a, t_rooms *r, char **arr)
{
	if (check_for_end(g, arr) == 1)
	{
		g->rooms = move_from_to(g, r, a->room, g->end_room);
		a->last = a->room;
		a->room = g->end_room;
        ft_putstr(a->name);
        ft_putchar('-');
        ft_putstr(a->room);
        ft_putchar(' ');
	}
	else	
	{
		while (*arr)
		{
			if (all_the_ifs(g, r, a, arr) == 1)
			{
				g->rooms = move_from_to(g, r, a->room, *arr);
				a->last = a->room;
				a->room = *arr;ft_putstr(a->name);
                ft_putchar('-');
                ft_putstr(a->room);
                ft_putchar(' ');
				break;
			}
			else
				//ft_debug(*arr, "not empty");
			arr++;
		}
	}
}

void		find_path(t_main *g)
{
	t_rooms 		*r;
	t_rooms	    	*head;
	t_links		    *l;
	char			**arr;
	int				i;

	r = g->rooms;
	head = g->rooms;
	l = g->links;
	while (r->next)
	{
		i = 0;
		arr = links(g, r->name);
        while (*arr)
        {
            if (is_room_valid(g, r, *arr) == 0)
                i++;
            arr++;
        }
        if (i == 1 && ft_strcmp(r->name, g->start_room) != 0 && ft_strcmp(r->name, g->end_room) != 0 && r->valid == 0)
        {
            r->valid = -1;
            r = head;
        }
		r = r->next;
	}
}

int			all_the_ifs(t_main *g, t_rooms *r, t_ants *a, char **arr)
{
	if ((ft_strcmp(*arr, g->end_room) == 0 || ants_in_room(g, r, *arr) == 0) && 
					ft_strcmp(g->end_room, a->room) != 0 && 
					ft_strcmp(a->last, *arr) != 0 &&
					ft_strcmp(*arr, g->start_room) != 0 &&
					is_room_valid(g, r, *arr) == 0)
		return (1);
	return (0);
}

int			is_room_valid(t_main *g, t_rooms *r, char *str)
{
	int		ret;

	g->rooms = r;
	ret = 0;
	while (g->rooms->next)
	{
		if (ft_strcmp(g->rooms->name, str) == 0)
		{
			ret = g->rooms->valid;
			break;
		}
		g->rooms = g->rooms->next;
	}
	g->rooms = r;
	return (ret);
}
