/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undefgeh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 12:44:18 by skavunen          #+#    #+#             */
/*   Updated: 2017/04/24 13:28:42 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_ucharmod(t_arg *arg)
{
	char		*d;
	char		c;

	c = ' ';
	if (arg->flag == 4)
		c = '0';
	d = ft_strcnew(arg->width, c);
	if (arg->just == 1)
		d[0] = arg->conv;
	else
		d[arg->width - 1] = arg->conv;
	return (d);
}

void			ft_undefbeh(t_arg *arg)
{
	char		*d;

	if (arg->conv == '\0')
	{
		d = ft_strnew(0);
		ft_putstr_f(d);
		free(d);
	}
	else if (arg->width < 0)
	{
		d = ft_strnew(1);
		d[0] = arg->conv;
		ft_putstr_f(d);
		free(d);
	}
	else
		ft_putstr_f(ft_ucharmod(arg));
}
