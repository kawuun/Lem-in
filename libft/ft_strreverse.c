/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:08:49 by skavunen          #+#    #+#             */
/*   Updated: 2016/12/08 16:20:22 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strreverse(const char *s)
{
	char		*d;
	size_t		a;
	size_t		i;
	size_t		j;

	a = ft_strlen(s);
	d = ft_strnew(a);
	i = 0;
	j = a - 1;
	while (i < a)
		d[i++] = s[j--];
	d[i] = '\0';
	return (d);
}
