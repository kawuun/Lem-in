/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:38:35 by skavunen          #+#    #+#             */
/*   Updated: 2016/12/12 12:53:04 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_helpme(int n, char *d, int flag, int k)
{
	d[k] = '\0';
	if (n == 0)
		d[0] = '0';
	if (flag == 1)
	{
		flag = 0;
		d[0] = '-';
		d[--k] = (char)((n % 10) + 48 + 1);
		n = n / 10;
	}
	while (n > 0)
	{
		d[--k] = (char)((n % 10) + 48);
		n = n / 10;
	}
	return (d);
}

char		*ft_itoa(int n)
{
	int		k;
	int		flag;
	char	*d;
	int		a;

	k = 0;
	flag = 0;
	if (n < 0)
	{
		flag = 1;
		n = (-n) - 1;
		k++;
	}
	a = n;
	if (a == 0)
		k++;
	while (a > 0)
	{
		k++;
		a = a / 10;
	}
	if (!(d = (char *)malloc(sizeof(char) * k + 1)))
		return (NULL);
	return (ft_helpme(n, d, flag, k));
}
