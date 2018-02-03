/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 12:28:44 by skavunen          #+#    #+#             */
/*   Updated: 2016/12/02 13:25:06 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*d;
	int				a;

	a = 0;
	d = (unsigned char*)s;
	while (n != 0)
	{
		if (d[a] == (unsigned char)c)
			return (&d[a]);
		else
		{
			a++;
			n--;
		}
	}
	return (NULL);
}
