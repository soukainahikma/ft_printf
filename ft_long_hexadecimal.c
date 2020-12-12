/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_hexadecimal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:55:43 by shikma            #+#    #+#             */
/*   Updated: 2020/01/07 12:25:19 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_len_of_number(long unsigned int n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static char		*tab_hexa(int i)
{
	char *tmp;

	if (!(tmp = (char*)malloc(sizeof(char) * (i))))
		return (NULL);
	i = 0;
	while (i < 10)
	{
		tmp[i] = '0' + i;
		i++;
	}
	while (i >= 10 && i < 16)
	{
		tmp[i] = 'X' + i - 1;
		i++;
	}
	return (tmp);
}

char			*ft_long_hexadecimal(long unsigned int n)
{
	long unsigned int	reste;
	size_t				i;
	char				*result;
	char				*t;

	t = tab_hexa(16);
	reste = 0;
	i = ft_len_of_number(n);
	if (!(result = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	result[i] = '\0';
	if (n > 0 || n == 0)
	{
		while (n >= 10)
		{
			reste = n % 16;
			n = n / 16;
			result[--i] = t[reste];
		}
		if (n % 16 != 0)
			reste = n % 16;
		result[0] = t[reste];
	}
	free(t);
	return (result);
}
