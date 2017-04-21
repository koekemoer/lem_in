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
	int			in_room;
	struct s_rooms_list	*next;
}				t_rooms_list;

typedef struct			s_links_list
{
	char			*link;
	char			**arr;
	struct s_links_list	*next;
}				t_links_list;

typedef struct			s_ants_list
{
	char			*name;
	char			*room;
	struct s_ants_list	*next;
}				t_ants_list;

typedef	struct			s_main
{
	t_input_list		*data;
	char			*gnl;
	int			num_ants;
	int			num_rooms;
	int			num_links;
	t_rooms_list		*rooms;
	t_links_list		*links;
	t_ants_list		*ants;
	char			*start_room;
	char			*end_room;
	int			nr_end;
	int			start_flag;
	int			end_flag;
}				t_main;

void				error();
t_input_list			*save_input(t_main *g);
int				get_map(t_main *g);
t_ants_list			*save_ants(t_main *g);
t_ants_list			*assign_rooms(t_main *g);
void				fill_start_room(t_main *g);
char				*get_link(t_main *g, char *str);
char				**links(t_main *g, char *test);
void				travel(t_main *g);
t_rooms_list			*go_to_start(t_main *g, t_rooms_list *r);

#endif
