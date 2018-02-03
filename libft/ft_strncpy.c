/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:48:01 by skavunen          #+#    #+#             */
/*   Updated: 2016/12/02 13:33:27 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned long	a;
	unsigned long	b;

	a = 0;
	b = 0;
	while (a < len && src[a])
	{
		dst[a] = src[b];
		b++;
		a++;
	}
	while (a < len)
		dst[a++] = '\0';
	return (dst);
}
