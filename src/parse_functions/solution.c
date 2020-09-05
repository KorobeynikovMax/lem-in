/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 15:19:24 by bedavis           #+#    #+#             */
/*   Updated: 2020/09/05 15:19:26 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room              *findStartEndRoom(t_lem *lem, int flag)
{
    t_room          *tmp;

    tmp = lem->map;
    if (tmp == NULL)
        return (NULL);
    while (!(tmp->start_endFlag == flag))
    {
        if (tmp->next == NULL)
            return (NULL);
        tmp = tmp->next;
    }
    return (tmp);
}

void                solve(t_lem *lem)
{
    t_paths_list    *pathsList;
    t_room          *start;
    t_room          *end;

    start = findStartEndRoom(lem, 1);
    end = findStartEndRoom(lem, 2);


    ft_putstr("here print result\n");
    return;
}

