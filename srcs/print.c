/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 15:43:09 by skavunen          #+#    #+#             */
/*   Updated: 2018/01/19 15:43:09 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void		add_ret_end(t_ret **ret, t_ret *new)
{
	t_ret	*tmp;

	tmp = *ret;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*ret = new;
}

void		init_route(t_ret *new, char *name)
{
	new->name = ft_strdup(name);
	new->visit = -1;
	new->next = NULL;
	new->new = -1;
}

t_ret		**create_routes(t_lem *data, int len, t_ret **new)
{
	int		a;
	t_list	*tmp;
	t_room	*room;
	int		*id;
	t_ret	*store;

	new = (t_ret**)malloc(sizeof(t_ret*) * len);
	a = -1;
	data->ret = data->tmp;
	while (data->ret)
	{
		tmp = (t_list*)data->ret->content;
		new[++a] = NULL;
		while (tmp)
		{
			id = (int*)tmp->content;
			room = find_room(data->rooms, *id);
			store = (t_ret*)malloc(sizeof(t_room));
			init_route(store, room->name);
			add_ret_end(&new[a], store);
			tmp = tmp->next;
		}
		data->ret = data->ret->next;
	}
	return (new);
}

void		move_new(t_ret **routes, int *ant, int len, t_lem *data)
{
	int		i;

	if ((*ant) <= data->const_ant)
	{
		i = -1;
		while (++i < len && (*ant) <= data->const_ant)
		{
			routes[i]->visit = (*ant)++;
			write(1, " ", data->space ? 1 : 0);
			ft_printf("L[%d]-[%s]", (*ant) - 1, routes[i]->name);
			data->space = 1;
		}
	}
}

void		move_exist(t_ret *route, t_lem *data)
{
	while (route)
	{
		if (route->visit > 0)
		{
			if (route->next)
			{
				route->next->new = route->visit;
				write(1, " ", data->space ? 1 : 0);
				ft_printf("L[%d]-[%s]", route->visit, route->next->name);
				data->space = 1;
			}
			else
			{
				route->visit = -1;
				data->ants--;
			}
		}
		route->visit = route->new;
		route->new = -1;
		route = route->next;
	}
}

int			print_route(t_lem *data, int len)
{
	t_ret	**routes;
	t_ret	*tmp;
	int		ant;
	int		i;

	routes = create_routes(data, len, NULL);
	data->const_ant = data->ants;
	// for(int i = 0;i< len;i++)
	// {
	// 	tmp = routes[i];
	// 	while (tmp)
	// 	{
	// 		printf("[%s]", tmp->name);
	// 		if (tmp->next)
	// 			printf("->");
	// 		tmp = tmp->next;
	// 	}
	// 	printf("\nEND\n");
	// }
	// exit(0);
	ant = 1;
	data->space = 0;
	while (data->ants > 0)
	{
		i = -1;
		while (++i < len)
			move_exist(routes[i], data);
		move_new(routes, &ant, len, data);
		data->ants ? (void)write(1, "\n", 1) : NULL;
		data->space = 0;
	}
}
