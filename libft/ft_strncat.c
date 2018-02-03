/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:25:10 by skavunen          #+#    #+#             */
/*   Updated: 2016/12/02 13:29:05 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	a;
	size_t	i;

	i = 0;
	a = 0;
	while (dest[a] != '\0')
		a++;
	while (n > 0 && src[i])
	{
		dest[a + i] = src[i];
		i++;
		n--;
	}
	dest[a + i] = '\0';
	return (dest);
}
