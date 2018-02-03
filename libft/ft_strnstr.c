/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:47:20 by skavunen          #+#    #+#             */
/*   Updated: 2016/12/06 13:01:43 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t	a;
	size_t	i;

	a = 0;
	i = 0;
	if (!*lit)
		return ((char*)big);
	while (big[a] != '\0')
	{
		i = 0;
		if (len == 0)
			return (NULL);
		while ((lit[i] == big[a + i]) && (len - 1) >= i)
		{
			if (lit[i + 1] == '\0')
				return ((char*)&big[a]);
			i++;
		}
		len--;
		a++;
	}
	return (NULL);
}
