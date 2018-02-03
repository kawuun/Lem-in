/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:58:20 by skavunen          #+#    #+#             */
/*   Updated: 2017/02/02 17:24:06 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	int		i;
	size_t	res;
	char	*d;

	if (!s1 || !s2)
		return (NULL);
	a = 0;
	i = 0;
	res = ft_strlen(s1) + ft_strlen(s2);
	d = (char *)malloc(sizeof(char) * res + 1);
	if (!d)
		return (NULL);
	while (s1[i] != '\0')
		d[a++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		d[a++] = s2[i++];
	d[a] = '\0';
	return (d);
}
