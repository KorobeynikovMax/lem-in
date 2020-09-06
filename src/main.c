/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 14:53:34 by bedavis           #+#    #+#             */
/*   Updated: 2020/09/06 14:25:35 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			init_lem(t_lem **lem)
{
	if (!(*lem = (t_lem *)malloc(sizeof(t_lem))))
		exit(1);
	(*lem)->count_ants = 0;
	(*lem)->map = NULL;
	(*lem)->paths = NULL;
	(*lem)->start_room = NULL;
	(*lem)->end_room = NULL;
}

int				main()
{
	t_lem 		*lem;

	init_lem(&lem);
	parse_map(lem);
	/*solve(lem);*/
	printf("it works!");
	return (0);
}

