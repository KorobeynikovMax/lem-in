/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 17:04:12 by wanton            #+#    #+#             */
/*   Updated: 2020/09/05 19:26:37 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include "constants.h"

/*
**-----------------------------------Structs------------------------------------
*/

typedef struct				s_room			t_room;
typedef struct				s_room_address	t_room_address;
typedef struct				s_lem			t_lem;
typedef struct				s_paths_list	t_paths_list;

struct						s_room
{
	char					*name;
	int						x_coord;
	int						y_coord;
	int						visit_flag;
	int						start_end_flag;
	t_room_address			*links;
	struct s_room			*next;
};

struct						s_room_address
{
	t_room					*address;
	struct s_room_address	*next;
};

struct						s_paths_list
{
    t_room_address 			*path;
    struct s_paths_list		*next;
};

struct						s_lem
{
	int						count_ants;
	t_room					*map;
	t_room					*start_room;
	t_room					*end_room;
	t_paths_list			*paths;
	int						hasPath;
};

/*
**----------------------------------Functions-----------------------------------
*/

/*
**Parse map functions
*/

void						parse_map(t_lem *lem);
void						solve(t_lem *lem);
void						parseLinksRooms(t_lem *lem, char *line);
char						*parse_rooms(t_lem *lem);
t_room						*findRoom(t_lem *lem, char *room);
t_room						*findStartEndRoom(t_lem *lem, int flag);

/*
**Functions for error message
*/

void						exit_with_not_valid_map();
void						exit_with_read_error();
void						exit_with_malloc_error(void);

/*
**Protected library functions
*/

void						pft_get_next_line(const int fd, char **line);
void						pft_str_split(char ***buff, char *line);

/*
**Free functions
*/

void						free_char_buff(char **buff);
void						free_t_lem(t_lem *lem);

/*
**t_room functions
*/

void						add_new_room(t_room **last_room, t_lem *lem,
					char *line, int mod);

int							check_comment(const char *line);

/*
**find path functions
*/

void 						add_in_paths_list(t_paths_list **list,
							 t_room_address *cur);
t_room_address				*find_path(t_lem *lem);
t_room						*find_next(t_room *room, int index);

/*
**put indexes in algo functions
*/
void						delete_room_links(t_room *room);
void						addInRoomList(t_room_address **list, t_room *room);

/*
**put indexes in algo functions
*/

int 						count_of_rooms(t_lem *lem);
void						put_numbers(t_lem *lem);
int							put_numbers_from_links(t_room_address *address,
								 int index);
void						set_all_visit(t_lem *lem, int visit_flag);

#endif
