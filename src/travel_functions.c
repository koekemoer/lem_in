/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   travel_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoekemo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 11:14:42 by lkoekemo          #+#    #+#             */
/*   Updated: 2017/05/17 12:25:31 by lkoekemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		test_end(t_main *g, t_ants_list *a, t_rooms_list *r, char **arr)
{
	char	*tmp;

	tmp = g->start_room;
	ft_putendl("1");
	while (*arr)
	{
		ft_putendl("2");
		//tmp = a->room;
		if ((ft_strcmp(*arr, g->end_room) == 0 || ants_in_room(g, r, *arr) == 0)
					&& ft_strcmp(g->end_room, a->room) != 0 && ft_strcmp(tmp, *arr) != 0)
		
		{
			ft_putendl("3");
			tmp = a->room;
			g->rooms = move_from_to(g, r, a->room, *arr);
			a->room = *arr;
			break;
		}
		else
			ft_debug(*arr, "not empty");
		arr++;
	}
}

