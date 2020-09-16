/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_new_ant_on_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:16:36 by wanton            #+#    #+#             */
/*   Updated: 2020/09/16 15:16:36 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				is_new_path(t_paths_list *path)
{
	if (path->active_ants == 0 && path->ants_queue > 0)
		return (1);
	return (0);
}

void			move_new_ant(t_room_address *path, int ant_n)
{
	path->next->visitor_number = ant_n;
}

void			put_new_ant_on_path(t_lem *lem, t_paths_list *path, int ant_n)
{
	change_path_list_param(lem, path, path->path);
	move_new_ant(path->path, ant_n);
	print_ant(path->path->next);
}