/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:26:19 by skavunen          #+#    #+#             */
/*   Updated: 2016/12/02 13:29:41 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*dst;
	t_list	*r;

	if (!lst)
		return (NULL);
	dst = ft_lstnew(lst->content, lst->content_size);
	dst = f(dst);
	r = dst;
	lst = lst->next;
	while (lst)
	{
		dst->next = f(ft_lstnew(lst->content, lst->content_size));
		dst = dst->next;
		lst = lst->next;
	}
	dst->next = NULL;
	return (r);
}
