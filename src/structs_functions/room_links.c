/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 17:18:42 by bedavis           #+#    #+#             */
/*   Updated: 2020/09/12 17:18:46 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				delete_room_links(t_room *room)
{
	t_room_address *tmp;
	t_room_address *tmp2;

	tmp = room->links;
	while (tmp != NULL)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
	}
	room->links = NULL;
}

void				addin_roomlist(t_room_address **list, t_room *room)
{
	t_room_address  *tmp;

	tmp = (t_room_address *)malloc(sizeof(t_room_address));
	tmp->visitor_number = START_ROOM_NUMBER;
	tmp->address = room;
	tmp->next = *list;
	*list = tmp;
}

