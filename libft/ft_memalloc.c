/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:26:56 by skavunen          #+#    #+#             */
/*   Updated: 2016/11/28 17:52:24 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memalloc(size_t size)
{
	unsigned char	*s;
	int				a;

	a = 0;
	if (size > 65535)
		return (NULL);
	s = (unsigned char*)malloc(sizeof(unsigned char) * size + 1);
	if (s)
	{
		while (size != 0)
		{
			s[a] = 0;
			a++;
			size--;
		}
		s[a] = '\0';
		return (s);
	}
	else
		return (NULL);
}
