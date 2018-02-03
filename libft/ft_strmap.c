/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:18:12 by skavunen          #+#    #+#             */
/*   Updated: 2016/12/05 14:45:01 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*d;

	if (!s)
		return (NULL);
	d = NULL;
	i = 0;
	d = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (d)
	{
		while (s[i] != '\0')
		{
			d[i] = f(s[i]);
			i++;
		}
		d[i] = '\0';
		return (d);
	}
	else
		return (NULL);
}
