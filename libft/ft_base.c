/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 13:49:40 by skavunen          #+#    #+#             */
/*   Updated: 2017/04/24 13:26:33 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_six(t_arg *arg, va_list ap)
{
	uintmax_t	num;
	int			flag;

	flag = 0;
	if (arg->conv == 'X')
		flag++;
	if (arg->size == 6)
		num = va_arg(ap, size_t);
	else if (arg->size == 5)
		num = va_arg(ap, uintmax_t);
	else if (arg->size == 4)
		num = va_arg(ap, unsigned long long);
	else if (arg->size == 3)
		num = va_arg(ap, unsigned long);
	else if (arg->size == 2)
		num = (unsigned short)va_arg(ap, unsigned int);
	else if (arg->size == 1)
		num = (unsigned char)va_arg(ap, unsigned int);
	else
		num = va_arg(ap, unsigned int);
	ft_charmod(ft_itoa_base(num, 16, flag), arg, 1);
}

void			ft_eight(t_arg *arg, va_list ap)
{
	uintmax_t	num;
	int			flag;

	flag = 0;
	if (arg->conv == 'O')
		flag++;
	if (arg->size == 6)
		num = (size_t)va_arg(ap, size_t);
	else if (arg->size == 5)
		num = va_arg(ap, uintmax_t);
	else if (arg->size == 4)
		num = va_arg(ap, unsigned long long);
	else if (arg->size == 3 || flag == 1)
		num = va_arg(ap, unsigned long);
	else if (arg->size == 2)
		num = (unsigned short)va_arg(ap, unsigned int);
	else if (arg->size == 1)
		num = (unsigned char)va_arg(ap, unsigned int);
	else
		num = va_arg(ap, unsigned int);
	ft_charmod(ft_itoa_base(num, 8, flag), arg, 1);
}

void			ft_uten(t_arg *arg, va_list ap)
{
	uintmax_t	num;
	int			flag;

	flag = 0;
	if (arg->conv == 'U')
		flag++;
	if (arg->size == 6)
		num = (size_t)va_arg(ap, size_t);
	else if (arg->size == 5)
		num = va_arg(ap, uintmax_t);
	else if (arg->size == 4)
		num = va_arg(ap, unsigned long long);
	else if (arg->size == 3 || flag == 1)
		num = va_arg(ap, unsigned long);
	else if (arg->size == 2)
		num = (unsigned short)va_arg(ap, unsigned int);
	else if (arg->size == 1)
		num = (unsigned char)va_arg(ap, unsigned int);
	else
		num = va_arg(ap, unsigned int);
	ft_charmod(ft_itoa_base(num, 10, flag), arg, 1);
}
