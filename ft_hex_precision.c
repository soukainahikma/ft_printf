/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 13:55:29 by shikma            #+#    #+#             */
/*   Updated: 2020/01/06 20:51:37 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hex_precision(t_flags *flags, unsigned int h)
{
	int		i;
	int		zero;
	char	*tmp;
	char	*str_zero;

	tmp = ft_hexadecimal(h);
	i = 0;
	zero = flags->n_precision - ft_strlen(tmp);
	if (zero < 0)
	{
		if (h == 0 && flags->precision == 1)
			return (ft_strdup(""));
		else
			return (tmp);
	}
	else
	{
		if (!(str_zero = (char *)malloc(zero + 1)))
			return (NULL);
		while (i < zero)
			str_zero[i++] = '0';
		str_zero[i] = '\0';
		return (ft_strjoin(str_zero, tmp));
	}
}
