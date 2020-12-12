/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_only_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 18:14:47 by shikma            #+#    #+#             */
/*   Updated: 2020/01/06 19:14:19 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_only_int(t_flags *flags, int integer)
{
	int number;

	number = 0;
	if (integer == 0 && flags->precision == 1 && flags->n_precision == 0)
		return (ft_strdup(""));
	if (integer >= 0)
		return (ft_int_precision(flags, integer));
	else
	{
		number = (-1) * integer;
		flags->minus = 1;
		return (ft_int_precision(flags, number));
	}
}
