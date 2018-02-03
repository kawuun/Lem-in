/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 16:52:14 by skavunen          #+#    #+#             */
/*   Updated: 2017/12/28 16:52:14 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

#include "../libft/libft.h"
#include <pthread.h>

typedef struct  s_room
{
    int     x;
    int     y;
    char    *name;
    int     id;
    int     flag;
    t_list  *lnk;
}               t_room;

typedef struct  s_lem
{
    int     ants;
    int     const_ant;
    int     space;
    int     nb_room;
    int     id_start;
    int     id_end;
    t_list  *rooms;
    int     **links;
    int     **visit;
    t_list  *ret;
    t_list  *tmp;
}               t_lem;

typedef struct  s_ret
{
    char            *name;
    int             visit;
    int             new;
    struct s_ret    *next;
}               t_ret;

t_room      *find_room(t_list *rooms, int id);
 
#endif