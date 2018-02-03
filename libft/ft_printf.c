/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 13:55:16 by skavunen          #+#    #+#             */
/*   Updated: 2017/04/24 13:27:22 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_printf(const char *src, ...)
{
	va_list		ap;
	int			i;

	i = 0;
	g_wr = 0;
	va_start(ap, src);
	while (src[i])
	{
		if (src[i] == '%')
		{
			i = ft_start(ap, src, i + 1);
		}
		else
		{
			ft_putchar_f(src[i]);
			i++;
		}
	}
	va_end(ap);
	return (g_wr);
}
