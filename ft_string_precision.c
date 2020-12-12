/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 21:50:40 by shikma            #+#    #+#             */
/*   Updated: 2020/01/06 20:43:29 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_string_precision(t_flags *flags, char *str)
{
	char	*dest;
	int		i;
	int		len;

	i = 0;
	if (flags->zero == 1 && flags->sign == 0)
		flags->precision = 0;
	if (str == NULL)
		str = ft_strdup("(null)");
	len = ft_strlen(str);
	if (flags->n_precision >= len)
		return (ft_strdup(str));
	if (!(dest = (char *)malloc(flags->n_precision + 1)))
		return (NULL);
	while (i < flags->n_precision)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
