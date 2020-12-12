/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_only_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 18:32:11 by shikma            #+#    #+#             */
/*   Updated: 2020/01/06 21:20:36 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_only_char(t_flags *flags, int c)
{
	char *result;

	flags->precision = 0;
	if (flags->width == 1)
	{
		if (flags->n_width > 0)
			flags->n_width = flags->n_width - 1;
		if (flags->sign == 1)
		{
			write(1, &c, 1);
			result = ft_width(flags, "");
			ft_putstr_fd(result, 1);
			free(result);
		}
		else if (flags->sign == 0)
		{
			result = ft_width(flags, "");
			ft_putstr_fd(result, 1);
			free(result);
			write(1, &c, 1);
		}
	}
	else
		write(1, &c, 1);
	return (NULL);
}
