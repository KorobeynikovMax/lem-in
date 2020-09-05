/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_protocol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 16:38:33 by wanton            #+#    #+#             */
/*   Updated: 2020/09/05 18:28:35 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		exit_with_not_valid_map(void)
{
	ft_putstr_fd("Error: map not valid\n", 2);
	exit(1);
}

void		exit_with_read_error(void)
{
	ft_putstr_fd("Error: map is not readable\n", 2);
	exit(1);
}

void		exit_with_malloc_error(void)
{
	ft_putstr_fd("Error: not enough memory\n", 2);
	exit(1);
}
