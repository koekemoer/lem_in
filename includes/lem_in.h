/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoekemo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 13:57:32 by lkoekemo          #+#    #+#             */
/*   Updated: 2017/05/19 14:12:26 by lkoekemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# include <fcntl.h>

typedef	struct			s_input_list
{
	char				*str;
	struct s_input_list	*next;
}						t_input;

typedef struct			s_rooms_list
{
	char				*name;
	int					valid;
	int					in_room;
	struct s_rooms_list	*next;
}						t_rooms;

typedef struct			s_links_list
{
	char				*link;
	char				**arr;
	struct s_links_list	*next;
}						t_links;

typedef struct			s_ants_list
{
	char				*name;
	char				*room;
	char				*last;
	struct s_ants_list	*next;
}						t_ants;

typedef	struct			s_main
{
	t_input				*data;
	char				*gnl;
	int					num_ants;
	int					num_rooms;
	int					num_links;
	t_rooms				*rooms;
	t_links				*links;
	t_ants				*ants;
	char				*start_room;
	char				*end_room;
	int					nr_end;
	int					start_flag;
	int					end_flag;
}						t_main;

void					error();
t_input					*save_input(t_main *g);
int						get_map(t_main *g);
t_ants					*save_ants(t_main *g);
t_ants					*assign_rooms(t_main *g);
void					fill_start_room(t_main *g);
char					*get_link(t_main *g, char *str);
char					**links(t_main *g, char *test);
void					travel(t_main *g);
t_rooms					*go_to_start(t_main *g, t_rooms *r);
t_rooms					*go_to_room(t_main *g, char *str);
void					test_end(t_main *g, t_ants *a, t_rooms *r, char **arr);
int						ants_in_room(t_main *g, t_rooms *r, char *str);
t_rooms					*move_from_to(t_main *g, t_rooms *r, char *from,
						char *to);
char					**links(t_main *g, char *test);
void					find_path(t_main *g);
int						all_the_ifs(t_main *g, t_rooms *r, t_ants *a,
						char *str);
int						is_room_valid(t_main *g, t_rooms *r, char *str);
void					print_name(char *name, char *room);
void					free_all(t_links *l, t_rooms *r, t_ants *a, t_input *i);
void                    print_map(t_main *g);
void	                print_arr(char **arr);

#endif
