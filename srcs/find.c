/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 16:52:34 by skavunen          #+#    #+#             */
/*   Updated: 2017/12/28 16:52:34 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_room      *find_room(t_list *rooms, int id)
{
    t_room  *pos;

    pos = NULL;
    while (rooms)
    {
        pos = (t_room*)rooms->content;
        if (pos->id ^ id)
            rooms = rooms->next;
        else      
            break ;
    }
    return (pos);
}

int         is_link(t_list *rooms, int id, int link)
{
    int     *tmp;
    t_room  *pos;
    t_list  *node;

    while (rooms)
    {
        pos = (t_room*)rooms->content;
        if (pos->id == id)
        {
            node = pos->lnk;
            while (node)
            {
                tmp = node->content;
                if (*tmp == link)
                    return (1);
                node = node->next;
            }
            return (0);
        }
        rooms = rooms->next;
    }
    return (-1);
}

void        bone_visit(int **data, int len)
{
    int     i;
    int     j;

    i = -1;
    while (++i < len)
    {
        j = -1;
        while (++j < len)
            if (data[i][j] != 3)
                data[i][j] = 0;
    }

}

void        make_visit(t_lem *data, int len)
{
    int     **tab;
    int     i;

    if (!(tab = (int**)malloc(sizeof(int*) * len)))
        exit(EXIT_FAILURE);
    i = -1;
    while (++i < len)
    {
        if (!(tab[i] = (int*)malloc(sizeof(int) *len)))
            exit(EXIT_FAILURE);
        ft_bzero(tab[i], len);
    }
    data->visit = tab;
}

void        make_links(t_lem *data, int len)
{
    int     **tab;
    int i;
    int j;

    i = -1;
    if (!(tab = (int**)malloc(sizeof(int*) * len)))
        exit(EXIT_FAILURE);
    while (++i < len)
    {
        if (!(tab[i] = (int*)malloc(sizeof(int) * len)))
            exit(EXIT_FAILURE);
        j = -1;
        while (++j < len)
        {
            if (j == i)
                tab[i][j] = 0;
            else
                if ((tab[i][j] = is_link(data->rooms, i, j)) < 0)
                    exit(EXIT_FAILURE);
        }
    }
    data->links = tab;
}

int         is_route(int **tab, int i, int pos, int len)
{
    if (pos < 0 || i < 0 || i >= len || pos >= len)
        return (-1);
    while (pos < len)
    {
        if (tab[i][pos] == 1)
            return (pos);
        pos++;
    }
    return (-1);
}

int        make_routes(t_lem *data, int s, int e, int prev)
{
    int     move;
    int     ret;
    int     tmp;

    if (s < 0 || s >= data->nb_room)
        return (0);
    if (data->links[s][e])
    {
        data->visit[s][e] = 3;
        return (1);
    }
    move = 0;
    ret = 0;
    while ((ret = is_route(data->links, s, ret, data->nb_room)) >= 0)
    {
        if (data->visit[ret][s] > 0)
		{
            ret++;
            continue;
		}
        data->visit[ret][s] = 1;
        if (ret != prev && make_routes(data, ret, data->id_end, s))
        {
            data->visit[ret][s] = 3;
            ft_lstadd((t_list**)&data->ret->content, ft_lstnew(&ret, sizeof(ret)));
            return (1);
        }
    }
    return (0);

}

int         find_path(t_lem *data)
{
    int         ret;
    t_list      *prev;

    data->visit = NULL;
    prev = NULL;
    if (data->id_start >= 0 && data->id_end >= 0)
    {
        make_links(data, data->nb_room);
        make_visit(data, data->nb_room);
        ret = 0;
        data->ret = ft_lstnew(NULL, 0);
        data->tmp = data->ret;
        while ((ret = is_route(data->links, data->id_start, ret, data->nb_room)) >= 0)
        {
            data->visit[ret][data->id_start] = 1;
            if (make_routes(data, ret, data->id_end, data->id_start))
            {
                data->visit[ret][data->id_start] = 3;
                ft_lstadd((t_list**)&data->ret->content, ft_lstnew(&ret, sizeof(ret)));
                ft_lstpushback((t_list**)&data->ret->content, &data->id_end, sizeof(data->id_end));
                data->ret->next = ft_lstnew(NULL, 0);
                prev = data->ret;
                data->ret = data->ret->next;
                bone_visit(data->visit, data->nb_room);
            }
            else
            {
                for(int i = 0;i < data->nb_room; i++)
                    for (int j = 0;j < data->nb_room;j++)
                        data->visit[i][j] = 0;
            }
            data->links[data->id_start][ret] = 0;
        }
        free(prev->next);
        prev->next = NULL;
        // printf("\nCHECKING.....");
        // t_list *node = data->tmp;
        // while (node)
        // {
        //     t_list *tmp = node->content;
        //     if (node->next)
        //         printf("\nGO!\n");
        //     while (tmp)
        //     {
        //         int *var = tmp->content;
        //         printf("{%d}", *var);
        //         if (tmp->next)
        //             printf(" -> ");
        //         else
        //             printf("END ROUTE\n");
        //         tmp = tmp->next;
        //     }
        //     node = node->next;
        // }
        // printf("End");
        // printf("\n");
        // exit(0);
        if (ret < 0 && !data->tmp->content)
            return (0);
        return (1);
    }
    return (0);
}