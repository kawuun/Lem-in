/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 16:52:21 by skavunen          #+#    #+#             */
/*   Updated: 2017/12/28 16:52:22 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int     main(void)
{
    t_lem   *data;

    data = (t_lem*)malloc(sizeof(t_lem));
    data->rooms = NULL;
    data->nb_room = 0;
    data->id_start = -1;
    data->id_end = -1;
    if (parse_input(data))
    {
        print_route(data, ft_lstlen(data->tmp));
        exit(0);
    }
    exit(1);
}