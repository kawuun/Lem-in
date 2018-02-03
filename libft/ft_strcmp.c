/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 12:41:41 by skavunen          #+#    #+#             */
/*   Updated: 2016/11/28 17:16:04 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 == '\0' && *s2 == '\0')
			return (0);
		else if (*s1 != *s2)
			return ((*(unsigned char*)s1) - (*(unsigned char*)s2));
		s1++;
		s2++;
	}
	return (0);
}
