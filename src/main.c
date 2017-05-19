/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoekemo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:05:21 by lkoekemo          #+#    #+#             */
/*   Updated: 2017/05/19 14:20:21 by lkoekemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	error(void)
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

int		main(void)
{
	t_main		g;

	g.data = save_input(&g);
	init(&g);
	get_map(&g);
	ft_putstr("\n");
	travel(&g);
	return (0);
}
