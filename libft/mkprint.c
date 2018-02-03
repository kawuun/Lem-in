/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mkprint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 12:45:16 by skavunen          #+#    #+#             */
/*   Updated: 2017/04/24 13:28:20 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_easychar(t_arg *arg, va_list ap)
{
	intmax_t	num;

	if (arg->size == 1 && arg->conv != 'D')
		num = (signed char)va_arg(ap, int);
	else if (arg->size == 2 && arg->conv != 'D')
		num = (short)va_arg(ap, int);
	else if (arg->size == 3 || arg->conv == 'D')
		num = va_arg(ap, long);
	else if (arg->size == 4)
		num = va_arg(ap, long long);
	else if (arg->size == 5)
		num = va_arg(ap, intmax_t);
	else if (arg->size == 6)
		num = va_arg(ap, size_t);
	else
		num = va_arg(ap, int);
	ft_charmod(ft_itoaspec(num), arg, 0);
}

void			ft_string(t_arg *arg, va_list ap)
{
	char		*d;
	wchar_t		*data;

	d = NULL;
	if (arg->size == 3 || arg->conv == 'S')
	{
		data = va_arg(ap, wchar_t*);
		if (data == NULL)
			data = L"(null)";
		ft_widestr(data, arg);
		return ;
	}
	else
		d = va_arg(ap, char*);
	if (d == NULL)
		d = "(null)";
	ft_addto(d, arg);
}

void			ft_char(t_arg *arg, va_list ap)
{
	int			c;
	char		ch;

	ch = ' ';
	c = va_arg(ap, int);
	if (arg->width > 0)
	{
		if (arg->flag == 4)
			ch = '0';
		if (arg->just == 1)
		{
			ft_putchar_f(c);
			ft_place_char(arg->width - 1, ch);
		}
		else
		{
			ft_place_char(arg->width - 1, ch);
			ft_putchar_f(c);
		}
	}
	else
		ft_putchar(c);
}

void			ft_mkprint(t_arg *arg, va_list ap)
{
	if (arg->conv == 'd' || arg->conv == 'D' || arg->conv == 'i')
		ft_easychar(arg, ap);
	if (arg->conv == 'S' || arg->conv == 's')
		ft_string(arg, ap);
	if (arg->conv == 'c' || arg->conv == 'C')
		ft_char(arg, ap);
	if (arg->conv == 'x' || arg->conv == 'X')
		ft_six(arg, ap);
	if (arg->conv == 'o' || arg->conv == 'O')
		ft_eight(arg, ap);
	if (arg->conv == 'u' || arg->conv == 'U')
		ft_uten(arg, ap);
	if (arg->conv == 'p')
		ft_pointer(arg, ap);
}
