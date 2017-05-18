/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   travel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoekemo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:06:13 by lkoekemo          #+#    #+#             */
/*   Updated: 2017/05/18 13:05:16 by lkoekemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include <stdio.h>  // REMOVE

t_rooms_list	*go_to_start(t_main *g, t_rooms_list *r)
{
	g->rooms = r;
	while (g->rooms->next)
	{
		if (ft_strcmp(g->rooms->name, g->start_room) == 0)
			break;
		g->rooms = g->rooms->next;
	}
	//	ft_putstr("GO TO START func: ");
	//	ft_putendl(g->rooms->name);
	return (g->rooms);
}

t_rooms_list	*go_to_room(t_main *g, char *str)
{
	//	t_rooms_list		*ph;

	//	ph = g->rooms;
	while (g->rooms->next)
	{
		if (ft_strcmp(g->rooms->name, str) == 0)
		{
			//g->rooms->in_room++;
			break;
		}
		g->rooms = g->rooms->next;
	}
	//	ft_putstr("WENT TO ROOM : ");
	//	ft_putendl(g->rooms->name);
	//	ft_putendl(" ");
	//	g->rooms = ph;
	return (g->rooms);
}

t_rooms_list	*move_from_to(t_main *g, t_rooms_list *r, char *from, char *to)
{
	g->rooms = r;
	while (g->rooms->next) // CONCIDER USING go_to_room
	{
		if (ft_strcmp(g->rooms->name, from) == 0 && 
				ft_strcmp(g->rooms->name, g->end_room) != 0)
		{
			g->rooms->in_room--;
			break;
		}
		g->rooms = g->rooms->next;
	}
	g->rooms = r;
	while (g->rooms->next) // CONCIDER USING go_to_room
	{
		if (ft_strcmp(g->rooms->name, to) == 0)
		{
			g->rooms->in_room++;
			break;
		}
		g->rooms = g->rooms->next;
	}
	return (r);
}

int	ants_in_room(t_main *g, t_rooms_list *r, char *str)
{
	int		ret;
	//t_rooms_list	*r;

	g->rooms = r;
	ret = 0;
	//ft_putstr("CURRENT ROOM BEFORE FUNC: ");
	//ft_putendl(g->rooms->name);
	while (g->rooms->next) // CONCIDER go_to_room
	{
		if (ft_strcmp(g->rooms->name, str) == 0)
		{
			ret = g->rooms->in_room;
			//g->rooms = r;
			break;
		}
		g->rooms = g->rooms->next;
	}
	g->rooms = r;
	//ft_putstr("CURRENT ROOM AFTER FUNC: ");
	//ft_putendl(g->rooms->name);
	return (ret);
}

/* SKRYF 'N FUNCTION WAT KYK OF EEN VAN DIE LINKS 'END' IS, DAT AS DIT IS, DAT HY ONMIDDELIK SOONTOE MOET GAAN 
   EN... DALK KAN JY IETS SKRYF WAT 'n FIXED ARRAY IS, SOOS 'n SIZE VAN DIE HOEVEELHEID ROOMS WAT DAAR IS */

void		travel(t_main *g)
{
	char		**arr;
	t_rooms_list	*r;
	t_ants_list	*a;
	int			test = 0;

	r = g->rooms;
	a = g->ants;
	find_path(g);
	while ((ants_in_room(g, r, g->end_room) != g->num_ants))
	{
		test++;
		ft_debug("NUMBER OF LOOPS", ft_itoa(test));
		ft_putendl("\n ### OUTER LOOP ###");
		a = g->ants;
//		ft_debug("STARTING_ANT", a->name);
		test = ants_in_room(g, r, g->end_room); 
		ft_debug("ANTS IN END", ft_itoa(test));
		while (a->next)
		{
			ft_putendl("\n # START OF LOOP #");
			ft_debug("ANT_NAME", a->name);
			ft_debug("ANT_ROOM", a->room);	
			arr = links(g, a->room);
			test_end(g, a, r, arr);
			a = a->next;
		}

	}
	test = ants_in_room(g, r, g->end_room);
	ft_debug("ANTS AT END OUTSIDE OF OUTER WHILE", ft_itoa(test));
	ft_debug("NUMBER OF LOOPS", ft_itoa(test));
}
