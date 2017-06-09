/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerasmus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 17:18:11 by jerasmus          #+#    #+#             */
/*   Updated: 2017/05/28 16:01:44 by lkoekemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	error(void)
{
	ft_putendl("ERROR");
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

void	print_name(char *name, char *room)
{
	ft_putstr(name);
	ft_putchar('-');
	ft_putstr(room);
	ft_putchar(' ');
}

void    print_map(t_main *g)
{
    t_input *node;

    node = g->data;
    if (g->num_ants == 0)
    {
        g->num_ants = ft_atoi(node->str);
        ft_putendl(node->str);
    }
}

int		main(void)
{
	t_main		g;

	g.data = NULL;
	g.data = save_input(&g);
	init(&g);
	get_map(&g);
    if (g.num_ants == 0 || g.num_links == 0 || g.num_rooms == 0)
        error();
	ft_putstr("\n");
	travel(&g);
	free_all(g.links, g.rooms, g.ants, g.data);
	return (0);
}
