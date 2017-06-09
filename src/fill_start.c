/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerasmus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 17:16:12 by jerasmus          #+#    #+#             */
/*   Updated: 2017/05/25 17:16:17 by jerasmus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		fill_start_room(t_main *g)
{
	t_rooms		*tmp;

	tmp = g->rooms;
	while (g->rooms->next)
	{
		if (ft_strcmp(g->rooms->name, g->start_room) == 0)
			g->rooms->in_room = g->num_ants;
		g->rooms = g->rooms->next;
	}
	g->rooms = tmp;
}

char		*get_link(t_main *g, char *str)
{
	char	*ret;

	ret = NULL;
	while (g->links->next && ret == NULL)
	{
		if (ft_strcmp(str, g->links->arr[0]) == 0)
			ret = g->links->arr[1];
		else if (ft_strcmp(str, g->links->arr[1]) == 0)
			ret = g->links->arr[0];
		g->links = g->links->next;
	}
	return (ret);
}

char		**links(t_main *g, char *test)
{
	char		**arr;
	char		*tmp;
	t_links		*head;
	int			i;

	tmp = NULL;
	i = 0;
	head = g->links;
	while ((get_link(g, test)) != NULL)
		i++;
    //ft_debug("I", ft_itoa(i));
	g->links = head;
	if (!(arr = (char**)ft_memalloc(sizeof(char*) * (i + 1))))
		return (NULL);
	i = 0;
	/*while ((tmp = get_link(g, test)))
	{
		//ft_strcpy(arr[i], tmp);
		if (tmp != NULL)
		{
			arr[i] = ft_strdup(tmp);
			//free(tmp);
			i++;
		}
		//i++;
	}*/
	while ((arr[i] = get_link(g, test)))
    {
		ft_debug("ARR[i]", arr[i]);
		i++;
	}
	arr[i] = 0;
	g->links = head;
	return (arr);
}
