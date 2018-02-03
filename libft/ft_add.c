/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 16:14:07 by skavunen          #+#    #+#             */
/*   Updated: 2017/04/24 13:29:31 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_addto(char *d, t_arg *arg)
{
	int		len;
	char	c;
	char	*tmp;

	c = ' ';
	if (arg->prec < (int)ft_strlen(d) && arg->prec != -1)
		d = ft_strsub(d, 0, arg->prec);
	len = ft_strlen(d);
	if (arg->width > len)
	{
		if (len == 0 && arg->conv == 'c')
			arg->width--;
		if (arg->flag == 4 && arg->sign != 2)
			c = '0';
		tmp = ft_strcnew(arg->width - len, c);
		if (arg->just == 1)
			d = ft_strjoin(d, tmp);
		else
			d = ft_strjoin(tmp, d);
		free(tmp);
	}
	ft_putstr_f(d);
	free(arg);
}
