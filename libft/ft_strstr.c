/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:54:08 by skavunen          #+#    #+#             */
/*   Updated: 2016/12/02 13:17:15 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *big, const char *lit)
{
	int		a;
	int		i;

	a = 0;
	i = 0;
	if (lit[i] == '\0')
		return ((char*)big);
	while (big[a] != '\0')
	{
		i = 0;
		while (lit[i] == big[a + i])
		{
			if (lit[i + 1] == '\0')
				return ((char*)&big[a]);
			i++;
		}
		a++;
	}
	return (NULL);
}
