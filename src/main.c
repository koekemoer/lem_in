/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoekemo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:05:21 by lkoekemo          #+#    #+#             */
/*   Updated: 2017/05/18 11:16:51 by lkoekemo         ###   ########.fr       */
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

	g.data = save_input(&g);
	init(&g);

	get_map(&g);
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
