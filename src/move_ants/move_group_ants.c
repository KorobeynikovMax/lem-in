/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_group_ants.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:26:42 by wanton            #+#    #+#             */
/*   Updated: 2020/09/16 15:26:42 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			clear_final_room(t_room_address *path, t_lem *lem)
{
	if (path->address == lem->end_room)
		path->visitor_number = 0;
}

void			move_ant(t_room_address *room, t_paths_list *path, t_lem *lem)
{
	change_path_list_param(lem, path, room);
	room->next->visitor_number = room->visitor_number;
	room->visitor_number = 0;
}

t_room_address	*find_ant_for_move(t_paths_list *path)
{
	t_room_address		*curr;

	curr = path->path;
	while (curr->next != NULL)
	{
		if (curr->visitor_number != 0 && curr->next->visitor_number == 0)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}

int				count_ants_to_move(t_room_address *path)
{
	int					count_ants;
	t_room_address		*current;

	count_ants = 0;
	current = path;
	while (current != NULL)
	{
		if (current->visitor_number != 0)
			count_ants++;
		current = current->next;
	}
	return (count_ants);
}

void			move_group_ants(t_lem *lem, t_paths_list *head)
{
	int					count_ants;
	t_room_address		*curr_room;

	count_ants = count_ants_to_move(head->path);
	while (count_ants-- > 0)
	{
		curr_room = find_ant_for_move(head);
		move_ant(curr_room, head, lem);
		print_ant(curr_room->next);
		clear_final_room(curr_room->next, lem);
	}
}
