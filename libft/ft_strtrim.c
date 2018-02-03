/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:21:06 by skavunen          #+#    #+#             */
/*   Updated: 2016/12/06 12:56:40 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_empty(char *d)
{
	d = (char *)malloc(sizeof(char) * 1);
	if (d)
	{
		d[0] = '\0';
		return (d);
	}
	else
		return (NULL);
}

static char		*ft_filld(char *d, char const *s, int c, int len)
{
	int			j;

	j = 0;
	d = (char *)malloc(sizeof(char) * (len + 1));
	if (!d)
		return (NULL);
	while (len--)
		d[j++] = s[c++];
	d[j] = '\0';
	return (d);
}

char			*ft_strtrim(char const *s)
{
	char		*d;
	int			a;
	int			len;
	int			i;

	d = NULL;
	if (!s)
	{
		d = ft_empty(d);
		return (d);
	}
	i = 0;
	a = (int)ft_strlen(s) - 1;
	while (s[a] == ' ' || s[a] == '\n' || s[a] == '\t')
		a--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	len = a - i + 1;
	if (i > 0 && s[i] == '\0')
	{
		d = ft_empty(d);
		return (d);
	}
	d = ft_filld(d, s, i, len);
	return (d);
}
