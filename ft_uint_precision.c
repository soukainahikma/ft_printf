/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 13:44:20 by shikma            #+#    #+#             */
/*   Updated: 2020/01/06 21:28:57 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_error(t_flags *flags, char **tmp, unsigned int u)
{
	if (u == 0 && flags->precision == 1)
	{
		free(*tmp);
		return (ft_strdup(""));
	}
	else
		return (*tmp);
}

char	*ft_uint_precision(t_flags *flags, unsigned int u)
{
	int		i;
	int		zero;
	char	*tmp;
	char	*str_zero;
	char	*dest;

	tmp = ft_uitoa(u);
	i = 0;
	zero = flags->n_precision - ft_strlen(tmp);
	if (zero < 0)
		return (ft_error(flags, &tmp, u));
	else
	{
		if (!(str_zero = (char *)malloc(zero + 1)))
			return (NULL);
		while (i < zero)
			str_zero[i++] = '0';
		str_zero[i] = '\0';
		dest = ft_strjoin(str_zero, tmp);
		free(str_zero);
		free(tmp);
		return (dest);
	}
}
