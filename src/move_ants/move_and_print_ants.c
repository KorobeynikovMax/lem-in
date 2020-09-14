/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_and_print_ants.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:18:19 by wanton            #+#    #+#             */
/*   Updated: 2020/09/14 14:48:41 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			is_close_path(t_paths_list *path)
{
	if (path->ants_queue == 0 && path->active_ants == 0)
		return (1);
	return (0);
}



void		transport_ants_to_next_room(t_lem *lem, t_paths_list *head,
								int *ant_num)
{
	t_paths_list		*current_path;

	current_path = head;
	while (current_path != NULL)
	{
		if (is_close_path(current_path))
			break ;
		current_path = current_path->next;
	}
}

void		move_and_print_ants(t_lem *lem, t_paths_list *head)
{
	int					flag;
	int					ant_number;

	ant_number = 1;
	flag = 1;
	while (flag)
	{
		flag = transport_ants(lem, head, &ant_number);
		ft_putchar('\n');
	}
}