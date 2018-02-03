/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_widehelp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 14:10:37 by skavunen          #+#    #+#             */
/*   Updated: 2017/04/24 13:27:57 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_wputstr(char **d)
{
	int		a;
	int		j;

	a = 0;
	while (d[a])
	{
		j = 0;
		while (d[a][j])
		{
			ft_putchar_f(d[a][j]);
			j++;
		}
		a++;
	}
}

int			ft_check_len_wch(char **data)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = 0;
	while (data[i])
	{
		tmp += ft_strlen(data[i]);
		i++;
	}
	return (tmp);
}

void		ft_place_char(int size, char c)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_putchar_f(c);
		i++;
	}
}
