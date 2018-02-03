/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:42:09 by skavunen          #+#    #+#             */
/*   Updated: 2017/04/24 13:26:53 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_len_num(unsigned long long value, int base)
{
	int		count;

	count = 0;
	if (value <= 0)
		count++;
	while (value != 0)
	{
		count++;
		value /= base;
	}
	return (count);
}

int			ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}

char		*ft_lower_case(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}

char		*ft_itoa_base(unsigned long long value, int base, int flag)
{
	char	*itoa;
	char	*box;
	size_t	len;

	box = "0123456789ABCDEF";
	len = ft_len_num(value, base);
	itoa = ft_strnew(len);
	if (itoa)
	{
		itoa[len] = '\0';
		if (value == 0)
			itoa[0] = '0';
		while (value != 0)
		{
			itoa[--len] = box[(value % base)];
			value = value / base;
		}
		if (flag == 0)
			itoa = ft_lower_case(itoa);
	}
	return (itoa);
}
