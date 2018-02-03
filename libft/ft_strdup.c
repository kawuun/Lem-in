/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:02:15 by skavunen          #+#    #+#             */
/*   Updated: 2016/12/02 13:21:44 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	char	*d;
	int		a;

	a = 0;
	while (s[a] != '\0')
		a++;
	d = (char *)malloc(sizeof(char) * a + 1);
	a = 0;
	if (!d)
		return (0);
	while (s[a] != '\0')
	{
		d[a] = s[a];
		a++;
	}
	d[a] = '\0';
	return (d);
}
