/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:03:26 by shikma            #+#    #+#             */
/*   Updated: 2020/01/06 18:24:07 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t		ft_intlen(unsigned int n)
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

static char			*myalloc(char *arr, int n)
{
	size_t			len;

	len = ft_intlen(n);
	if (!(arr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	arr[len] = '\0';
	return (arr);
}

char				*ft_uitoa(unsigned int n)
{
	int							r;
	unsigned int				len;
	char						*arr;

	len = ft_intlen(n);
	arr = NULL;
	arr = (char*)myalloc(arr, n);
	if (arr == NULL)
		return (NULL);
	while (0 < len)
	{
		r = n % 10;
		arr[len - 1] = r + '0';
		n = n / 10;
		len--;
	}
	return (arr);
}
