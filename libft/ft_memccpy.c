/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 12:04:06 by skavunen          #+#    #+#             */
/*   Updated: 2016/12/02 13:35:20 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*sorc;
	int				a;

	a = 0;
	dest = dst;
	sorc = (unsigned char*)src;
	while (n != 0)
	{
		if (sorc[a] == (unsigned char)c)
		{
			dest[a] = sorc[a];
			return (&dest[a + 1]);
		}
		dest[a] = sorc[a];
		a++;
		n--;
	}
	return (NULL);
}
