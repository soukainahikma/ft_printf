/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:37:13 by shikma            #+#    #+#             */
/*   Updated: 2020/01/08 17:33:22 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_zero_minus(int *i, int *j, t_flags *flags, const char *format)
{
	int count;

	count = 0;
	if (format[count] == '-')
	{
		flags->sign = 1;
		ft_skip_char(&format[count], j, i);
	}
	if (format[count] == '0')
	{
		if (format[count + 1] != '-' && format[count - 1] != '-')
		{
			flags->zero = 1;
			ft_skip_char(&format[count], j, i);
		}
		else
			ft_skip_char(&format[count], j, i);
	}
	return ;
}

void	check_negative_flags(int *i, int *j, t_flags *flags, const char *format)
{
	int count;

	count = 0;
	flags->width = 1;
	if (flags->width == 1 && flags->precision != 1)
	{
		if (flags->n_width < 0)
		{
			flags->n_width = (-1) * flags->n_width;
			flags->sign = 1;
			flags->zero = 0;
		}
		ft_skip_char(&format[count], j, i);
	}
	else if (flags->precision == 1)
	{
		if (flags->n_precision < 0)
		{
			flags->n_precision = (-1) * flags->n_precision;
			flags->precision = 0;
		}
		ft_skip_char(&format[count], j, i);
	}
	return ;
}

void	check_positive_width(int *i, int *j, t_flags *flags, const char *format)
{
	int count;

	if (flags->n_width > 0)
	{
		count = 0;
		flags->width = 1;
		ft_skip_char(&format[count], j, i);
	}
}

void	check_flags(int *i, t_flags *flags, const char *format, va_list *ap)
{
	int j;

	j = 0;
	while (format[j] == '-' || format[j] == '0')
		check_zero_minus(i, &j, flags, &format[j]);
	flags->n_width = ft_atoi(&format[j]);
	check_positive_width(i, &j, flags, &format[j]);
	if (format[j] == '*')
	{
		flags->n_width = va_arg(*ap, int);
		check_negative_flags(i, &j, flags, &format[j]);
	}
	if (format[j] == '.')
	{
		ft_skip_char(&format[j], &j, i);
		flags->precision = 1;
		flags->n_precision = ft_atoi(&format[j]);
		if (flags->n_precision > 0)
			ft_skip_char(&format[j], &j, i);
		else if (format[j] == '*')
		{
			flags->n_precision = va_arg(*ap, int);
			check_negative_flags(i, &j, flags, &format[j]);
		}
	}
}
