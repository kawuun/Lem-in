/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:43:03 by skavunen          #+#    #+#             */
/*   Updated: 2016/12/02 13:34:55 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*d;

	if (!s)
		return (NULL);
	d = NULL;
	i = 0;
	d = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (d)
	{
		while (s[i] != '\0')
		{
			d[i] = f(i, s[i]);
			i++;
		}
		d[i] = '\0';
		return (d);
	}
	else
		return (NULL);
}
