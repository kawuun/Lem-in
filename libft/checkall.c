/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:11:55 by skavunen          #+#    #+#             */
/*   Updated: 2017/04/24 13:26:17 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_flags(const char *src, int i, t_arg *arg)
{
	while (src[i] == '0' || src[i] == '+' || src[i] == '-'
			|| src[i] == '#' || src[i] == ' ')
	{
		if (src[i] == '-')
		{
			if (arg->flag == 4)
				arg->flag = -1;
			arg->just = 1;
		}
		if (src[i] == '+')
			arg->sign = 1;
		if (src[i] == '#')
			arg->sharp = 3;
		if (src[i] == '0' && arg->just != 1)
			arg->flag = 4;
		if (src[i] == ' ' && arg->sign != 1)
			arg->sign = 2;
		i++;
	}
	return (i);
}

int			ft_width(const char *src, int i, t_arg *arg, va_list ap)
{
	int		num;

	num = 0;
	if (src[i] >= '0' && src[i] <= '9')
	{
		while (src[i] >= '0' && src[i] <= '9')
		{
			num = num * 10 + src[i] - '0';
			i++;
		}
		arg->width = num;
	}
	else if (src[i] == '*')
	{
		arg->width = (int)va_arg(ap, int);
		if (arg->width < 0)
		{
			arg->width *= -1;
			arg->just = 1;
		}
		i++;
	}
	return (i);
}

int			ft_prec(const char *src, int i, t_arg *arg, va_list ap)
{
	int		num;

	num = 0;
	if (src[i] == '.')
	{
		i++;
		arg->prec = -2;
		if (src[i] == '*')
		{
			arg->prec = (int)va_arg(ap, int);
			if (arg->prec < 0)
				arg->prec = -1;
			i++;
		}
		else
		{
			while (src[i] >= '0' && src[i] <= '9')
			{
				num = num * 10 + src[i] - '0';
				i++;
			}
			arg->prec = num;
		}
	}
	return (i);
}

int			ft_sizemod(const char *src, int i, t_arg *arg)
{
	while (src[i] == 'l' || src[i] == 'h' || src[i] == 'j' || src[i] == 'z')
	{
		if (src[i] == 'z')
		{
			arg->size = 6;
			i++;
		}
		else if (src[i] == 'j' && arg->size < 5)
		{
			arg->size = 5;
			i++;
		}
		else if (src[i] == 'l' && arg->size < 4)
		{
			i = ft_howmanyc(src, i, 'l', arg);
		}
		else if (src[i] == 'h' && arg->size < 3)
		{
			i = ft_howmanyc(src, i, 'h', arg);
		}
		else
			i++;
	}
	return (i);
}
