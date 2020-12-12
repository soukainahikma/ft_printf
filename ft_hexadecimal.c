/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:50:42 by shikma            #+#    #+#             */
/*   Updated: 2020/01/08 17:58:42 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_len_of_number(unsigned int n)
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

char			*ft_hexadecimal(unsigned int n)
{
	unsigned int	reste;
	size_t			i;
	char			*result;
	char			*t;

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
