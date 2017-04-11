#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# include <fcntl.h>

typedef	struct			s_input_list
{
	char			*str;
	struct s_input_list	*next;
}				t_input_list;

typedef	struct			s_main
{
	t_input_list		*data;
	char			*gnl;
	int			num_ants;
	int			num_rooms;
}				t_main;

void				error();
t_input_list			*save_input(t_main *g);
int				get_map(t_main *g);


#endif
