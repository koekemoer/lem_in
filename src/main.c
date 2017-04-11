
#include "../includes/lem_in.h"

void	error()
{
	ft_putendl("ERROR BOETIE!");
	exit(1);
}

int	main()
{
	t_main		g;
	//t_input_list	i;

	g.data = save_input(&g);
	ft_putendl("SAVE INPUT DONE\nMAIN func");
	while (g.data->next)
	{
		ft_putendl(g.data->str);
		g.data = g.data->next;
	}
	ft_putendl("AG LEKKER!");
	return (0);
}
