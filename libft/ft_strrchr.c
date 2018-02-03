/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:03:25 by skavunen          #+#    #+#             */
/*   Updated: 2016/12/02 13:34:23 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		a;

	a = 0;
	while (s[a] != '\0')
		a++;
	if (!a)
		return (NULL);
	while (a >= 0)
	{
		if (s[a] == (char)c)
			return ((char*)&s[a]);
		a--;
	}
	return (NULL);
}
