#include "lem_in.h"

int    check_comment(const char *line)
{
    if (line[0] == '#' && line[1] != '#')
        return (1);
    else
        return (0);
}
int       check_mod(t_lem *lem, char *line, int *mod)
{
    if (ft_strcmp(line, "##start") == 0)
        *mod = START_ROOM_MODIFIER;
    else if (ft_strcmp(line, "##end") == 0)
        *mod = END_ROOM_MODIFIER;
    else
        return 0;
    return (1);
}
t_room *new_room(char *line)
{
    t_room *room;
    char   **buf;
    int    i = 0;
    room = (t_room *)malloc(sizeof(t_room));
    buf = ft_strsplit(line, ' ');
    room->name = ft_strdup(buf[0]);
    room->x_coord = ft_atoi(buf[1]);
    room->y_coord = ft_atoi(buf[2]);
    room->next = NULL;
    room->links = NULL;
    while (i < 3)
        free(buf[i++]);
    free(buf);
    return (room);
}
char   *parseRooms(t_lem *lem)
{
    int       start_end_mod;
    char   *line;
    t_room *room;
    int    flag = 1;
    t_room *tmp;
    start_end_mod = 0;
    while (1)
    {
        if (ft_get_next_line(0, &line) == -1)
            exitWithReadError();
        if (check_mod(lem, line, &start_end_mod) == 1)
        {
            free(line);
            continue;
        }
        if (check_comment(line))
        {
            free(line);
            continue;
        }
        if (ft_strchr(line, '-'))
            return (line);
        room = new_room(line);
        if (flag == 1)
        {
            flag = 0;
            lem->map = room;
            tmp = room;
        }
        tmp->next = room;
        tmp = room;
    }

}