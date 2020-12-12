/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 13:26:16 by shikma            #+#    #+#             */
/*   Updated: 2020/01/06 15:54:32 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_percent(t_flags *flags)
{
	char *dest;

	if (flags->zero == 1 && flags->sign == 0)
		flags->precision = 0;
	dest = ft_strdup("%");
	return (dest);
}
