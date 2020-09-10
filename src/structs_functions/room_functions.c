/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 18:59:38 by wanton            #+#    #+#             */
/*   Updated: 2020/09/06 15:00:36 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*new_room(char *line, int mod)
{
	char		**buff;
	t_room		*room;

	pft_str_split(&buff, line);
	if (!(room = (t_room *)malloc(sizeof(t_room))))
		exit_with_malloc_error();
	if (!(room->name = ft_strdup(buff[0])))
		exit_with_malloc_error();
	room->x_coord = ft_atoi(buff[1]);
	room->y_coord = ft_atoi(buff[2]);
	room->visit_flag = 0;
	room->start_end_flag = mod;
	room->next = NULL;
	room->links = NULL;
	free_char_buff(buff);
	return (room);
}

void		check_duplicate_and_exit(t_lem *lem, int mod)
{
	if (mod == START_ROOM_MODIFIER && lem->start_room != NULL)
		exit_with_not_valid_map();
	else if (mod == END_ROOM_MODIFIER && lem->end_room != NULL)
		exit_with_not_valid_map();
}

void		set_start_end_room(t_lem *lem, int mod, t_room *room)
{
	if (mod == START_ROOM_MODIFIER)
	{
		check_duplicate_and_exit(lem, mod);
		lem->start_room = room;
		room->start_end_flag = START_ROOM_MODIFIER;
	}
	else if (mod == END_ROOM_MODIFIER)
	{
		check_duplicate_and_exit(lem, mod);
		lem->end_room = room;
		room->start_end_flag = END_ROOM_MODIFIER;
	}
}

void		add_new_room(t_room **last_room, t_lem *lem, char *line, int mod)
{
	t_room		*room;

	room = new_room(line, mod);
	set_start_end_room(lem, mod, room);
	if ((*last_room) == NULL)
		lem->map = room;
	else
		(*last_room)->next = room;
	(*last_room) = room;
}
