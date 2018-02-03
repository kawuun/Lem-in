/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:37:09 by skavunen          #+#    #+#             */
/*   Updated: 2016/12/02 13:26:46 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	int				a;

	a = 0;
	s = (unsigned char*)s1;
	d = (unsigned char*)s2;
	while (n != 0)
	{
		if (s[a] != d[a])
			return (s[a] - d[a]);
		a++;
		n--;
	}
	return (0);
}
