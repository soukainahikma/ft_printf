/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 21:42:54 by shikma            #+#    #+#             */
/*   Updated: 2020/01/07 11:47:53 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_int(t_flags *flags, int d, char *tmp)
{
	char *dest;

	if (d == INT_MIN)
	{
		flags->minus = 0;
		return (tmp);
	}
	if (flags->minus == 1 && flags->zero == 0 && d != INT_MIN)
	{
		flags->minus = 0;
		dest = ft_strjoin("-", tmp);
		free(tmp);
		return (dest);
	}
	else
		return (tmp);
}

char	*check_minus(t_flags *flags, char *str_zero, int *i, int *zero)
{
	if (flags->minus == 1)
	{
		flags->minus = 0;
		if (!(str_zero = (char *)malloc((*zero)++)))
			return (NULL);
		str_zero[(*i)++] = '-';
	}
	else if (!(str_zero = (char *)malloc((*zero) + 1)))
		return (NULL);
	return (str_zero);
}

char	*ft_int_precision(t_flags *flags, int d)
{
	int		i;
	int		zero;
	char	*tmp;
	char	*str_zero;
	char	*dest;

	tmp = ft_itoa(d);
	str_zero = NULL;
	i = 0;
	if ((zero = flags->n_precision - ft_strlen(tmp)) < 0 || d == INT_MIN)
		return (check_int(flags, d, tmp));
	else
	{
		str_zero = check_minus(flags, str_zero, &i, &zero);
		while (i < zero)
			str_zero[i++] = '0';
		str_zero[i] = '\0';
		dest = ft_strjoin(str_zero, tmp);
		free(tmp);
		free(str_zero);
		return (dest);
	}
}
