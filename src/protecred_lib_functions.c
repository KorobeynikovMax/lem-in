/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protecred_lib_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 19:47:57 by wanton            #+#    #+#             */
/*   Updated: 2020/09/05 19:50:44 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		pft_get_next_line(const int fd, char **line)
{
	if (ft_get_next_line(fd, line) == -1)
		exit_with_read_error();
}

void		pft_str_split(char ***buff, char *line)
{
	char	**res;

	res = ft_strsplit(line, SEPARATOR_STRSPLIT);
	if (res == NULL)
		exit_with_malloc_error();
	(*buff) = res;
}