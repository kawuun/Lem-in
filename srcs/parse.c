/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 16:52:27 by skavunen          #+#    #+#             */
/*   Updated: 2017/12/28 16:52:28 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void    add_link(t_list *rooms, char *r1, char *r2)
{
    t_room *tmp;
    t_room *fst;
    t_room *sec;

    fst = NULL;
    sec = NULL;
    tmp = NULL;
    while (rooms)
    {
        if (sec && fst)
            break ;
        tmp = (t_room*)rooms->content;
        if (!ft_strcmp(tmp->name, r1))
            fst = tmp;
        else if (!ft_strcmp(tmp->name, r2))
            sec = tmp;
        rooms = rooms->next;
    }
    if (!fst || !sec)
    {
        write(1, "ERROR\n", 6);
        exit(EXIT_FAILURE);
    }
    ft_lstpushback(&fst->lnk, &sec->id, sizeof(sec->id));
    ft_lstpushback(&sec->lnk, &fst->id, sizeof(fst->id));
}

void    parse_link(t_lem *data, char *s)
{
    char *r1;
    char *r2;
    int i;

    i = -1;
    while (s[++i] ^ '-')
        ;
	if (!s[i + 1])
	{
		write(1, "ERROR\n", 6);
		exit(EXIT_FAILURE);
	}
    r1 = ft_strsub(s, 0, i);
    r2 = ft_strsub(s, i + 1, ft_strlen(s) - (i + 1));
    add_link(data->rooms, r1, r2);
}

void    parse_room(t_lem *data, int *f, char *s)
{
    t_room      *new;
    static int  id;
    int         i;

    s = ft_strtrim(s);
    i = -1;
    if (ft_strchr(s, '-'))
        parse_link(data, s);
    else
    {
        while (s[++i] && s[i] ^ ' ')
            ;
		if (!s[i])
		{
			write(1, "ERROR\n", 6);
			exit(EXIT_FAILURE);
		}
        new = (t_room*)malloc(sizeof(t_room));
        new->name = NULL;
        new->name = ft_strsub(s, 0, i);
        new->x = 0;
		if (!ft_isdigit(s[i + 1]))
		{
			write(1, "ERROR\n", 6);
			exit(EXIT_FAILURE);
		}
        while (ft_isdigit(s[++i]))
            new->x = new->x * 10 + s[i] - '0';
        new->y = ft_atoi(s + i);
        new->id = id++;
        new->lnk = NULL;
        data->nb_room = id;
        new->flag = *f;
        if (*f & 1)
            data->id_start = id - 1;
        else if (*f & 2)
            data->id_end = id - 1;
        *f = 0;
        ft_lstpushback(&data->rooms, new, sizeof(t_room));
        free(new);
    }
}

int    parse_input(t_lem *data)
{
    char    *line;
    int     flag;
    char    *tab[4096];
    int     a;

    a = 0;
    flag = 0;
    line = NULL;
    get_next_line(0, &line);
	if ((!ft_isdigit(line[0]) && line[0] != '+') || line[0] == '+' && !ft_isdigit(line[1]))
	{
		write(1, "ERROR\n", 6);
		exit(EXIT_FAILURE);
	}
    data->ants = ft_atoi(line);
    tab[a++] = line;
    while (get_next_line(0, &line) > 0)
    {
        if (line && line[0] && line[1] && !(line[0] ^ '#') && line[1] ^ '#')
            continue;
        else if (!ft_strcmp(line, "##start"))
            flag |= 1;
        else if (!ft_strcmp(line, "##end"))
            flag |= 2;
        else
            parse_room(data, &flag, line);
        tab[a++] = line;
    }
    tab[a] = NULL;
    if (find_path(data))
    {
        a = -1;
        while (tab[++a])
        {
            printf("{%s}\n", tab[a]);
            free(tab[a]);
        }
        return (1);
    }
    return (0);
}