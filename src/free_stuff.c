/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoekemo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 07:13:26 by lkoekemo          #+#    #+#             */
/*   Updated: 2017/05/28 14:10:07 by lkoekemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	free_links(t_links *l)
{
	t_links *tmp_l;

	while (l != NULL)
	{
		tmp_l = l;
		l = l->next;
		free_args(tmp_l->arr);
		free(tmp_l);
	}
	free(l);
}

void	free_rooms(t_rooms *r)
{
	t_rooms	*tmp_r;

	while (r != NULL)
	{
		tmp_r = r;
		r = r->next;
		free(tmp_r);
	}
	free(r);
}

void	free_ants(t_ants *a)
{
	t_ants	*tmp_a;

	while (a != NULL)
	{
		tmp_a = a;
		a = a->next;
		free(tmp_a->name);
		free(tmp_a);
	}
	free(a);
}

void	free_input(t_input *i)
{
	t_input	*tmp_i;

	while (i != NULL)
	{
		tmp_i = i;
		i = i->next;
		free(tmp_i->str);
		free(tmp_i);
	}
	free(i);
}

void	free_all(t_links *l, t_rooms *r, t_ants *a, t_input *i)
{
	free_links(l);
	free_rooms(r);
	free_ants(a);
	free_input(i);
}
