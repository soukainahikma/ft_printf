/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:31:05 by shikma            #+#    #+#             */
/*   Updated: 2020/01/06 18:12:13 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t		ft_intlen(int n)
{
	size_t			i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char			*myalloc(char *arr, int n, int *sign)
{
	size_t			len;

	len = ft_intlen(n);
	if (n >= 0)
	{
		if (!(arr = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		arr[len] = '\0';
	}
	else
	{
		if (!(arr = (char*)malloc(sizeof(char) * (len + 2))))
			return (NULL);
		*sign = 1;
		arr[0] = '-';
		arr[len + 1] = '\0';
	}
	return (arr);
}

char				*ft_itoa(int n)
{
	int							r;
	unsigned int				len;
	char						*arr;
	int							sign;

	sign = 0;
	len = ft_intlen(n);
	arr = NULL;
	arr = (char*)myalloc(arr, n, &sign);
	if (arr == NULL)
		return (NULL);
	while (0 < len)
	{
		if (n < 0)
			r = (n % 10) * (-1);
		else
			r = n % 10;
		arr[len + sign - 1] = r + '0';
		n = n / 10;
		len--;
	}
	return (arr);
}
