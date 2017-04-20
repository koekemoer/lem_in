#include "../includes/lem_in.h"

t_ants_list		*save_ants(t_main *g)
{
	t_ants_list	*head;
	t_ants_list	*node;
	int		i;

	head = NULL;
	i = 1;
	while (i <= g->num_ants)
	{
		if (head == NULL)
		{
			head = (t_ants_list *)malloc(sizeof(t_ants_list));
			node = head;
		}
		node->name = ft_strjoin("L", ft_itoa(i));
		//ft_putendl(node->name);
		node->next = (t_ants_list *)malloc(sizeof(t_ants_list));
		if (node->name == NULL || ft_strcmp("\0", node->name) == 0)
			error();
		i++;
		node = node->next;
	}
	//ft_putchar('\n');
	node->next = NULL;
	node = NULL;
	free(node);
	return (head);
}

//t_ants			*assign_rooms(t_main *g)
//{

