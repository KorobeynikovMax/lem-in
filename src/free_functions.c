/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 19:45:41 by wanton            #+#    #+#             */
/*   Updated: 2020/09/05 19:46:23 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		free_char_buff(char **buff)
{
	int			i;

	i = 0;
	while (buff[i] != NULL)
		free(buff[i++]);
	free(buff);
}

void		free_t_room(t_room *room)
{
	t_room		*p;
	t_room_address *tmp;
	t_room_address *tmp2;

	p = room;
	while (p != NULL)
	{
		tmp = p->links;
		while (tmp != NULL)
        {
		    tmp2 = tmp;
		    tmp = tmp->next;
            free(tmp2);
        }
		p = p->next;
	}
	p = room;
	while (p != NULL)
	{
		free(room->name);
		room = room->next;
		free(p);
		p = room;
	}
}

void		free_t_lem(t_lem *lem)
{
	lem->start_room = NULL;
	lem->end_room = NULL;
	free_t_room(lem->map);
	free(lem);
}