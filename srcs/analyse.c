/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 13:30:03 by skavunen          #+#    #+#             */
/*   Updated: 2018/01/27 13:30:03 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int				double_visit(int **tab, int len)
{
	int			i;
	int			j;

	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
			if (tab[i][j] == 2)
				return (1);
	}
	return (0);
}

int				ft_lstlen(t_list *node)
{
	int			count;

	count = 0;
	while (node)
	{
		count++;
		node = node->next;
	}
	return (count);
}

void			delete_list(t_list **node)
{
	t_list		*list;
	t_list		*next;

	list = *node;
	while (list)
	{
		next = list->next;
		free(list->content);
		free(list);
		list = next;
	}
}

void			analyse_list(t_lem *data, t_list *prev, int len)
{
	t_list		*node;

	if (!prev)
		return ;
	if (ft_lstlen(prev->content) > ft_lstlen(data->ret->content))
	{
		node = data->tmp;
		if (node == prev)
		{
			delete_list((t_list**)&prev->content);
			free(prev);
			data->tmp = data->ret;
		}
		else
		{
			while (node && node->next != prev)
				node = node->next;
			delete_list((t_list**)&prev->content);
			free(prev);
			node->next = data->ret;
		}
	}
	else
	{
		prev->next = NULL;
		delete_list((t_list**)&data->ret->content);
		free(data->ret);
		data->ret = prev;
	}
}