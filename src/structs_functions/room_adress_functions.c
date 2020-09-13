/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_adress_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 15:40:29 by wanton            #+#    #+#             */
/*   Updated: 2020/09/13 16:00:09 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


int			count_rooms(t_room_address *path)
{
	int				count;
	t_room_address	*p;

	count = 0;
	p = path;
	while (p->next != NULL)
	{
		count++;
		p = p->next;
	}
	return (count);
}