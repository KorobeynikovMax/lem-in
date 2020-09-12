/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 17:15:10 by bedavis           #+#    #+#             */
/*   Updated: 2020/09/12 17:15:12 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				set_all_visit(t_lem *lem, int visit_flag)
{
	t_room			*room;

	room = lem->map;
	while (room != NULL)
	{
		if (room->visit_flag >= 0)
			room->visit_flag = visit_flag;
		room = room->next;
	}
}

int					put_numbers_from_links(t_room_address *address, int index)
{
	t_room_address *tek;

	tek = address;
	while (tek != NULL)
	{
		if (tek->address->visit_flag == 0)
			tek->address->visit_flag = index + 1;
		if (tek->address->start_end_flag == END_ROOM_MODIFIER)
			return (1);
		tek = tek->next;
	}
	return (0);
}

void				put_numbers(t_lem *lem)
{
	t_room *tmp;
	int index;
	int isEnd;

	tmp = lem->map;
	index = 1;
	isEnd = 0;
	lem->start_room->visit_flag = index;
	while (!isEnd)
	{
		while (tmp != NULL)
		{
			if (tmp->visit_flag == index)
			{
				if (put_numbers_from_links(tmp->links, index))
					isEnd = 1;
			}
			tmp = tmp->next;
		}
		if (index > count_of_rooms(lem) && lem->hasPath == 0)
			exit_with_not_valid_map();
		if (index > count_of_rooms(lem) && lem->hasPath > 0)
			break;
		index++;
		tmp = lem->map;
	}
}

int 				count_of_rooms(t_lem *lem)
{
	t_room *tmp;
	int count;

	count = 0;
	tmp = lem->map;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}