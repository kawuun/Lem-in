/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chjoin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 15:10:54 by skavunen          #+#    #+#             */
/*   Updated: 2017/06/21 15:14:22 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_chjoin(char const *str, char ch)
{
	char	*new;
	int		a;

	a = 0;
	if (!str)
		return (NULL);
	new = (char*)malloc(sizeof(char) * ft_strlen(str) + 2);
	while (str[a] != '\0')
	{
		new[a] = str[a];
		a++;
	}
	new[a] = ch;
	new[++a] = '\0';
	return (new);
}
