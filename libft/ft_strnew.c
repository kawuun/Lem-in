/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:25:51 by skavunen          #+#    #+#             */
/*   Updated: 2016/11/28 15:31:57 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*s;
	int		i;

	i = 0;
	s = (char *)malloc(sizeof(char) * size + 1);
	if (s)
	{
		while (size != 0)
		{
			s[i] = '\0';
			i++;
			size--;
		}
		s[i] = '\0';
		return (s);
	}
	else
		return (NULL);
}
