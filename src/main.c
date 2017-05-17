/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoekemo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:05:21 by lkoekemo          #+#    #+#             */
/*   Updated: 2017/05/17 12:48:42 by lkoekemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include <stdio.h> //REMOVE

void	error()
{
	ft_putendl("ERROR BOETIE!");
	exit(1);
}

void	init(t_main *g)
{
	g->num_ants = 0;
	g->num_rooms = 0;
	g->num_links = 0;
	g->start_flag = 0;
	g->end_flag = 0;
	g->nr_end = 0;
}

int	main()
{
	t_main		g;
//	t_rooms_list	*r;
	//int		test;
	//t_input_list	i;

	g.data = save_input(&g);
	init(&g);
	ft_putendl("init");
//	r = g.rooms;

	get_map(&g);
	ft_putendl("get_map");
//	r = g.rooms;
//	printf("\nNUMBER OF ANTS: %d\n", g.num_ants);
//	printf("NUMBER OF ROOMS: %d\n", g.num_rooms);
//	printf("NUMBER OF LINKS: %d\n", g.num_links);
//	printf("START-ROOM: %s\n", g.start_room);
//	printf("END-ROOM: %s\n\n", g.end_room);
//	t_rooms_list *r = g.rooms;
//	fill_start_room(&g/*, g.rooms*/);
//	g.rooms = r;
//	printf("\nROOMS:\n");
/*	while (g.rooms->next)
	{
		ft_putendl(g.rooms->name);
		g.rooms = g.rooms->next;
	}*/
//	printf("LINKS:\n");
//	char	*test;
//	int	i = 0;
/*	while (g.links->next)
	{
		//i = 0;
		ft_putendl(g.links->link);
		while (g.links->arr[i])
		{
			printf("NUMBER %d: %s\n", i, g.links->arr[i]);
			i++;
		}
//		test = get_link(&g, "END");
//		ft_putstr("TEST: ");
//		ft_putendl(test);
		//
		g.links = g.links->next;
	}*/
//	g.rooms = r;
	ft_putchar('\n');
//	printf("#####END_ROOM: %s\n", g.end_room);
	travel(&g);



	return (0);
}
