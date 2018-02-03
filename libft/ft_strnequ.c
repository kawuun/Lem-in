/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:26:06 by skavunen          #+#    #+#             */
/*   Updated: 2016/12/05 14:45:49 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned long	a;

	a = 0;
	if ((!s1 && s2) || (!s2 && s1) || (!s1 && !s2))
		return (0);
	while (a < n)
	{
		if (s1[a] != s2[a])
			return (0);
		else
			a++;
	}
	return (1);
}
