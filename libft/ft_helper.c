/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:27:54 by skavunen          #+#    #+#             */
/*   Updated: 2017/04/24 13:26:42 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_widthhelp(char *s, t_arg *arg, int len, char c)
{
	char	*tmp;
	char	*buf;

	tmp = s;
	buf = ft_strcnew(arg->width - len, c);
	if (arg->just == 1)
		s = ft_strjoin(s, buf);
	else
		s = ft_strjoin(buf, s);
	free(tmp);
	free(buf);
	return (s);
}

char		*ft_precjoin(char *d, int i, char ch)
{
	char	*tmp;
	char	*buf;

	tmp = d;
	buf = ft_strcnew(i, ch);
	d = ft_strjoin(buf, d);
	free(tmp);
	free(buf);
	return (d);
}

int			ft_prechelp(char *s, char *c)
{
	int plus;

	plus = 0;
	if (s[0] == '+' || s[0] == '-' || s[0] == ' ')
	{
		plus = 1;
		c[0] = s[0];
	}
	else if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
	{
		plus = 2;
		c[0] = s[0];
		c[1] = s[1];
	}
	return (plus);
}

char		*ft_signhelp(char *s, t_arg *arg)
{
	char	*tmp;
	char	*buf;

	buf = ft_strnew(1);
	tmp = s;
	if (arg->sign == 1)
		buf[0] = '+';
	else if (arg->sign == 2)
		buf[0] = ' ';
	if (s[0] != '-' && buf[0] != '\0')
	{
		s = ft_strjoin(buf, s);
		free(tmp);
	}
	free(buf);
	return (s);
}
