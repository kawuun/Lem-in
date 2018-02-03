/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:49:54 by skavunen          #+#    #+#             */
/*   Updated: 2016/12/02 13:26:20 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned long	a;
	char			*d;

	if (!s)
		return (NULL);
	a = 0;
	d = NULL;
	d = (char *)malloc(sizeof(char) * len + 1);
	if (d)
	{
		while (a < len)
		{
			d[a] = s[start];
			start++;
			a++;
		}
		d[a] = '\0';
		return (d);
	}
	else
		return (NULL);
}
