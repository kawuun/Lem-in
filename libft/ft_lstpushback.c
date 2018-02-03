/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpuchback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:53:13 by skavunen          #+#    #+#             */
/*   Updated: 2017/03/06 14:59:18 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstpushback(t_list **list, void *content, size_t size)
{
	t_list		*node;

	node = *list;
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = ft_lstnew(content, size);
	}
	else
		*list = ft_lstnew(content, size);
}
