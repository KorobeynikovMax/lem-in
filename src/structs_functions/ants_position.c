/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 16:32:16 by wanton            #+#    #+#             */
/*   Updated: 2020/09/13 16:40:17 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ants_position		*create_new_ant(t_lem *lem, int number)
{
	t_ants_position		*ant;

	ant = (t_ants_position *)malloc(sizeof(t_ants_position) * lem->count_ants);
	if (ant == NULL)
		exit_with_malloc_error();
	ant->ant_number = number;
	ant->path_number = START_PATH_NUMBER;
	ant->room_number = START_ROOM_NUMBER;
	ant->next = NULL;
	return (ant);
}