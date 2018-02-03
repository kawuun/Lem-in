/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:30:13 by skavunen          #+#    #+#             */
/*   Updated: 2016/12/07 18:41:16 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		d;
	size_t		a;

	d = 0;
	a = 0;
	while (dst[d])
		d++;
	while (src[a] && (d + 1) < size)
		dst[d++] = src[a++];
	dst[d] = '\0';
	if (!a)
		d = size;
	while (src[a++])
		d++;
	return (d);
}
