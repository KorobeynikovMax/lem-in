/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 14:53:34 by bedavis           #+#    #+#             */
/*   Updated: 2020/09/03 13:35:55 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			init_lem(t_lem **lem)
{
	if (!(*lem = (t_lem *)malloc(sizeof(t_lem))))
		exit(1);
	(*lem)->countAnts = 0;
	(*lem)->map = NULL;
}

int				main()
{
	t_lem 		*lem;

	init_lem(&lem);
	parseMap(lem);

	printf("it works!");
	return (0);
}
