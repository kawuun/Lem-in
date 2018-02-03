/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:57:40 by skavunen          #+#    #+#             */
/*   Updated: 2017/04/24 13:27:14 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_pointer(t_arg *arg, va_list ap)
{
	uintmax_t	ptr;
	char		*s;
	char		*buf;
	char		*tmp;

	ptr = (uintmax_t)va_arg(ap, void *);
	buf = ft_strnew(2);
	buf[0] = '0';
	buf[1] = 'x';
	if (ptr == 0 && arg->prec != -1)
		s = buf;
	else
	{
		tmp = ft_itoa_base(ptr, 16, 0);
		s = ft_strjoin(buf, tmp);
		free(buf);
		free(tmp);
	}
	ft_charmod(s, arg, 1);
}
