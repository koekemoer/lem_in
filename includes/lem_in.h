#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# include <fcntl.h>

/*
	STILL HAVE TO CHECK FOR 'L' AND '#'
   */

typedef	struct			s_input_list
{
	char			*str;
	struct s_input_list	*next;
}				t_input_list;

typedef struct			s_rooms_list
{
	char			*name;
	struct s_rooms_list	*next;
}				t_rooms_list;

typedef struct			s_links_list
{
	char			*link;
	struct s_links_list	*next;
}				t_links_list;

typedef	struct			s_main
{
	t_input_list		*data;
	char			*gnl;
	int			num_ants;
	int			num_rooms;
	int			num_links;
	t_rooms_list		*rooms;
	t_links_list		*links;
	char			*start_room;
	char			*end_room;
	int			start_flag;
	int			end_flag;
}				t_main;

void				error();
t_input_list			*save_input(t_main *g);
int				get_map(t_main *g);


#endif
