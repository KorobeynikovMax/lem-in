/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 17:10:48 by bedavis           #+#    #+#             */
/*   Updated: 2020/09/12 17:10:50 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void 				add_in_paths_list(t_paths_list **list, t_room_address *cur)
{
	t_paths_list *tmp;

	tmp = (t_paths_list *)malloc(sizeof(t_paths_list));
	tmp->path = cur;
	tmp->next = *list;
	*list = tmp;
}

t_room				*find_next(t_room *room, int index)
{
	t_room_address *tmp;

	tmp = room->links;
	while (tmp != NULL)
	{
		if (tmp->address->visit_flag == index)
			return (tmp->address);
		tmp = tmp->next;
	}
	return (NULL);
}

t_room_address 		*find_path(t_lem *lem)
{
	t_room_address *result;
	t_room *next;
	t_room *prev;
	int index;

	result = NULL;
	if (lem->end_room->visit_flag == 0)
		return (NULL);
	index = lem->end_room->visit_flag - 1;
	addInRoomList(&result, lem->end_room);
	prev = lem->end_room;
	while (1)
	{
		next = find_next(prev, index);
		if (next == NULL)
			break;
		addInRoomList(&result, next);
		if (prev->start_end_flag == 0)
			prev->visit_flag = -1;
		prev = next;
		index--;
	}
	if (result != NULL && result->address->start_end_flag == START_ROOM_MODIFIER)
		lem->hasPath = 1;
	return (result);
}