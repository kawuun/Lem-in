/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 14:23:41 by skavunen          #+#    #+#             */
/*   Updated: 2017/04/24 13:28:27 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_checkconv(t_arg *arg)
{
	if (arg->conv != 's' && arg->conv != 'S' && arg->conv != 'd'
		&& arg->conv != 'D' && arg->conv != 'o' && arg->conv != 'O'
		&& arg->conv != 'i' && arg->conv != 'u' && arg->conv != 'U'
		&& arg->conv != 'x' && arg->conv != 'X' && arg->conv != 'c'
		&& arg->conv != 'C' && arg->conv != 'p')
		return (0);
	return (1);
}

int			ft_checkall(const char *src, int i, va_list ap, t_arg *arg)
{
	int		index;
	int		a;

	a = 1;
	index = i;
	while (a > 0)
	{
		a = index;
		index = ft_flags(src, index, arg);
		index = ft_width(src, index, arg, ap);
		index = ft_prec(src, index, arg, ap);
		index = ft_sizemod(src, index, arg);
		if (index == a)
			a = -1;
	}
	arg->conv = src[index];
	if (src[index] == '\0')
		return (index);
	return (index + 1);
}

void		ft_createarg(t_arg *arg)
{
	arg->just = -1;
	arg->sign = -1;
	arg->flag = -1;
	arg->width = -1;
	arg->prec = -1;
	arg->size = -1;
	arg->sharp = -1;
}

int			ft_start(va_list ap, const char *src, int i)
{
	t_arg	*arg;
	int		index;

	index = 0;
	arg = (t_arg*)malloc(sizeof(t_arg));
	ft_createarg(arg);
	index = ft_checkall(src, i, ap, arg);
	if (ft_checkconv(arg) == 0)
		ft_undefbeh(arg);
	else
		ft_mkprint(arg, ap);
	return (index);
}
