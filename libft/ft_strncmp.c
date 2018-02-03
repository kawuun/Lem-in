/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 14:20:51 by skavunen          #+#    #+#             */
/*   Updated: 2016/11/28 18:31:10 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t a;

	a = 0;
	while (n > 0)
	{
		if (*s1 == '\0' && *s2 == '\0')
			return (0);
		else if (*s1 != *s2)
			return ((*(unsigned char*)s1) - (*(unsigned char*)s2));
		s1++;
		s2++;
		n--;
	}
	return (0);
}
