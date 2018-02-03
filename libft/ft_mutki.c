/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutki.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:11:39 by skavunen          #+#    #+#             */
/*   Updated: 2017/04/24 13:27:03 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_addsharp(char *s, t_arg *arg)
{
	char	*tmp;
	char	*buf;

	if (arg->sharp == 3 && s[0] != '0')
	{
		buf = ft_strnew(2);
		tmp = s;
		if ((arg->conv == 'x' || arg->conv == 'X') && s[0] != '\0')
		{
			buf[0] = '0';
			buf[1] = arg->conv;
		}
		else if (arg->conv == 'o' || arg->conv == 'O')
			buf[0] = '0';
		s = ft_strjoin(buf, s);
		free(tmp);
		free(buf);
	}
	return (s);
}

void		ft_charmod(char *s, t_arg *arg, int un)
{
	if (arg->prec == -2 || arg->prec == 0)
	{
		if ((s[0] == '0' || !s) && arg->conv != 'p')
			s = ft_strnew(0);
	}
	if (un != 1 && s[0] != '\0')
		s = ft_signhelp(s, arg);
	else if (un == 1)
		s = ft_addsharp(s, arg);
	if (arg->prec > 0)
		s = ft_addprec(s, arg->prec, '0');
	s = ft_addwidth(s, arg, ft_strlen(s), ' ');
	free(arg);
	ft_putstr_f(s);
	free(s);
}

char		*ft_addwidth(char *s, t_arg *arg, int len, char c)
{
	if (arg->width > len)
	{
		if (arg->prec < 0 && arg->just != 1 && arg->flag == 4)
		{
			if (arg->sign == 2 || s[0] == '-' || s[0] == '+' || s[0] == ' ')
				arg->width -= 1;
			if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
				arg->width -= 2;
			return (ft_addprec(s, arg->width, '0'));
		}
		else
			s = ft_widthhelp(s, arg, len, c);
	}
	return (s);
}

char		*ft_addprec(char *s, int count, char ch)
{
	int		plus;
	char	*c;
	char	*d;
	char	*tmp;
	int		i;

	c = ft_strnew(2);
	plus = ft_prechelp(s, c);
	i = ft_strlen(s) - plus;
	if (i < count)
	{
		d = ft_strsub(s, plus, i);
		free(s);
		d = ft_precjoin(d, count - i, ch);
		if (plus > 0)
		{
			tmp = d;
			d = ft_strjoin(c, d);
			free(tmp);
		}
		free(c);
		return (d);
	}
	free(c);
	return (s);
}
