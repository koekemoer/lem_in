
#include "../includes/lem_in.h"

void	error()
{
	ft_putendl("ERROR BOETIE!");
	exit(1);
}

int	main()
{
	t_main		g;

	g.data = save_input(&g);
	//ft_putendl("AG LEKKER!");
	return (0);
}
