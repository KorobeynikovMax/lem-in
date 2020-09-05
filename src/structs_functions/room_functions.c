/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 18:59:38 by wanton            #+#    #+#             */
/*   Updated: 2020/09/05 19:26:37 by wanton           ###   ########.fr       */
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
	free_char_buff(buff);
	return (room);
}

void		add_new_room(t_room **last_room, t_lem *lem, char *line, int mod)
{
	t_room		*room;

	room = new_room(line, mod);
	if (last_room == NULL)
		lem->map = room;
	else
		(*last_room)->next = room;
	(*last_room) = room;
}
