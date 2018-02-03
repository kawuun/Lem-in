/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:04:42 by skavunen          #+#    #+#             */
/*   Updated: 2017/04/24 13:28:33 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_howmanyc(const char *src, int i, char c, t_arg *arg)
{
	int			count;

	count = 0;
	while (src[i] == c)
	{
		count++;
		i++;
	}
	if ((count % 2) == 0)
	{
		if (c == 'l')
			arg->size = 4;
		else
			arg->size = 1;
	}
	else
	{
		if (c == 'l')
			arg->size = 3;
		else if (arg->size == 2)
			arg->size = 1;
		else
			arg->size = 2;
	}
	return (i);
}

void			f_ten(intmax_t value, char *str, intmax_t base, int *i)
{
	char		*tmp;

	tmp = "0123456789ABCDEF";
	if (value <= -base || value >= base)
		f_ten(value / base, str, base, i);
	str[(*i)++] = tmp[A(value % base)];
}

char			*ft_itoaspec(intmax_t value)
{
	int			i;
	char		*str;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * 32)))
		return (0);
	if (value < 0)
		str[i++] = '-';
	f_ten(value, str, 10, &i);
	str[i] = '\0';
	return (str);
}

void			ft_putchar_f(int c)
{
	write(1, &c, 1);
	g_wr++;
}
