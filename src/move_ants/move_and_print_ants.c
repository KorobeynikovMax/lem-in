/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_and_print_ants.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:18:19 by wanton            #+#    #+#             */
/*   Updated: 2020/09/13 17:18:19 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ants_position		*chose_ant(t_ants_position *first_ant)
{
	t_ants_position		*ant;

	ant = first_ant;
	while (ant != NULL)
	{
		if (ant->path_number != PATH_NUMBER_CLOSE)
			return (ant);
		ant = ant->next;
	}
	return (NULL);
}

void		move_and_print_ants(t_lem *lem, t_ants_position *ants_pos,
						  int *rooms_numbers, int count_paths) {
	int					i;
	int					flag;
	t_ants_position		*ant;

	flag = 1;
	while (flag == 1)
	{
		flag = 0;
		i = 0;
		ant = ants_pos;
		while (i++ < count_paths)
		{
			if (ant->path_number == PATH_NUMBER_CLOSE)
				i--;
			else
			{
				flag = 1;
			}
			ant = ant->next == NULL ? ants_pos : ant->next;
		}
	}
}