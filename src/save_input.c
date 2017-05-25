/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerasmus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 17:17:53 by jerasmus          #+#    #+#             */
/*   Updated: 2017/05/25 17:30:25 by jerasmus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_input_list			*save_input(t_main *g)
{
	t_input_list		*head;
	t_input_list		*node;

	head = NULL;
	while (get_next_line(0, &g->gnl))
	{
		if (head == NULL)
		{
			head = (t_input_list *)malloc(sizeof(t_input_list));
			node = head;
		}
		node->str = g->gnl;
		node->next = (t_input_list *)malloc(sizeof(t_input_list));
		if (node->str == NULL || (ft_strcmp(node->str, "\0") == 0))
			error();
		node = node->next;
		ft_putendl(g->gnl);
	}
	node->next = NULL;
	node = NULL;
	free(node);
	return (head);
}
