/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 13:38:11 by skavunen          #+#    #+#             */
/*   Updated: 2017/04/24 13:29:18 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_putstr_f(const char *src)
{
	int				a;

	a = 0;
	while (src[a] != '\0')
	{
		ft_putchar_f(src[a]);
		a++;
	}
}

char				*ft_strcnew(int size, char c)
{
	char			*dst;
	int				a;

	a = 0;
	dst = (char*)malloc(sizeof(char) * size + 1);
	while (a < size)
	{
		dst[a] = c;
		a++;
	}
	dst[a] = '\0';
	return (dst);
}
