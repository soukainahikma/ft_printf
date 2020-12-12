/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 20:07:57 by shikma            #+#    #+#             */
/*   Updated: 2020/01/06 21:38:28 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fill_width_precision(t_flags *flags, int len)
{
	int		i;
	char	*dest;

	i = 0;
	if (!(dest = (char *)malloc(len + 1)))
		return (NULL);
	if (flags->precision == 1 || (flags->width == 1 && flags->zero == 0))
	{
		while (i < len)
			dest[i++] = ' ';
		if (flags->minus == 1)
			dest[len - 1] = '-';
	}
	if (flags->zero == 1)
	{
		while (i < len)
		{
			dest[i++] = '0';
			if (flags->minus == 1)
				dest[0] = '-';
		}
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_width(t_flags *flags, char *str)
{
	char	*dest;
	int		len;
	char	*tmp;

	if ((len = flags->n_width - ft_strlen(str)) <= 0)
	{
		if (flags->minus == 1)
			return (ft_strjoin("-", str));
		else
			return (ft_strdup(str));
	}
	dest = fill_width_precision(flags, len);
	if (flags->sign == 1)
	{
		tmp = ft_strjoin(str, dest);
		free(dest);
		return (tmp);
	}
	else
	{
		tmp = ft_strjoin(dest, str);
		free(dest);
		return (tmp);
	}
}
