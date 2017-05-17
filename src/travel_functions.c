/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   travel_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoekemo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 11:14:42 by lkoekemo          #+#    #+#             */
/*   Updated: 2017/05/17 17:59:21 by lkoekemo         ###   ########.fr       */
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

void		test_end(t_main *g, t_ants_list *a, t_rooms_list *r, char **arr)
{
	if (check_for_end(g, arr) == 1)
	{
		ft_debug("TEST_END", "END_ROOM FOUND");
		ft_debug("ANT_ROOM BEFORE SWITCH", a->room);
		g->rooms = move_from_to(g, r, a->room, g->end_room);
		a->last = a->room;
		a->room = g->end_room;
		ft_debug("ANT->CURRENT", a->room);
		ft_debug("ANT->LAST", a->last != NULL ? a->last : "NUL OU BUL");
		ft_debug("ANT_ROOM AFTER SWITCH", a->room);
	}
	else	
	{
		ft_debug("TEST_END", "END_ROOM NOT FOUND");
		while (*arr)
		{
			if ((ft_strcmp(*arr, g->end_room) == 0 || 
					ants_in_room(g, r, *arr) == 0) && 
					ft_strcmp(g->end_room, a->room) != 0 && 
					ft_strcmp(a->last, *arr) != 0 &&
					ft_strcmp(*arr, g->start_room) != 0)
			{
				ft_debug("ANT_ROOM BEFORE SWITCH", a->room);
				g->rooms = move_from_to(g, r, a->room, *arr);
				a->last = a->room;
				a->room = *arr;
				ft_debug("ANT->CURRENT", a->room);
				ft_debug("ANT->LAST", a->last != NULL ? a->last : "NUL OU BUL");
				ft_debug("ANT_ROOM AFTER SWITCH", a->room);
				break;
			}
			else
				ft_debug(*arr, "not empty");
			arr++;
		}
	}
}

void		find_path(t_main *g)
{
	t_rooms_list	*r;

	r = g->rooms;
	while (r->next)
	{
		ft_debug("FIND PATH", r->name);
		r = r->next;
	}
}
