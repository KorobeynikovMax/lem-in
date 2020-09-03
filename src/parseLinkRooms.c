/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseLinkRooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 15:05:00 by bedavis           #+#    #+#             */
/*   Updated: 2020/09/03 15:05:02 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int     isValidLink(char *line, char **r1, char **r2)
{
    char		**split;

    if (*line == '#')
        return (1);
    split = ft_strsplit(line, '-');
    if ((!split[0] || split[0][0] == 'L') && (!split[1] || split[1][0] == 'L'))
        return (0);
    if (!(split[2] == NULL))
        return (0);
    *r1 = split[0];
    *r2 = split[1];
    return (1);
}

void	parseLinksRooms(t_lem *lem, char *line)
{
    char		*str;
    char        *r1;
    char        *r2;

    if (isValidLink(line, &r1, &r2))
        exitWithNotValidMap();
    while (ft_get_next_line(0, &str))
    {
        if (!isValidLink(str, &r1, &r2))
            exitWithNotValidMap();
        else
        {

        }
    }

}
