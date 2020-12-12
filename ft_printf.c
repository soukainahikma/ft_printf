/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 18:57:05 by shikma            #+#    #+#             */
/*   Updated: 2020/01/07 12:47:40 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_specifier_precision(t_flags *flags, const char *format, va_list *ap)
{
	char	*tmp;

	if (format[0] == 'd' || format[0] == 'i')
		return (ft_only_int(flags, va_arg(*ap, int)));
	else if (format[0] == '%')
		return (ft_percent(flags));
	else if (format[0] == 'c')
		return (ft_only_char(flags, va_arg(*ap, int)));
	else if (format[0] == 's' && flags->precision == 1)
		return ((ft_string_precision(flags, va_arg(*ap, char*))));
	else if (format[0] == 's' && flags->precision == 0)
		return (ft_only_string(va_arg(*ap, char*)));
	else if (format[0] == 'u')
		return ((ft_uint_precision(flags, (va_arg(*ap, unsigned int)))));
	else if (format[0] == 'X')
		return (ft_strtoup(ft_hex_precision(flags, va_arg(*ap, unsigned int))));
	else if (format[0] == 'x')
		return (ft_hex_precision(flags, va_arg(*ap, unsigned int)));
	else if (format[0] == 'p')
		return (ft_address((long unsigned int)va_arg(*ap, long unsigned int)));
	if (!(tmp = malloc(2)))
		return (0);
	tmp[0] = format[0];
	tmp[1] = 0;
	return (tmp);
}

char	*ft_precision(const char *format, t_flags *flags, va_list *list)
{
	char	*result;
	char	*tmp;
	int		i;

	i = 0;
	if (flags->precision == 1)
		result = ft_specifier_precision(flags, &format[i], list);
	else
	{
		flags->n_precision = 0;
		result = ft_specifier_precision(flags, &format[i], list);
	}
	if (flags->width == 1 && format[i] != 'c')
	{
		tmp = result;
		result = ft_width(flags, result);
		free(tmp);
	}
	return (result);
}

void	ft_counter_1(const char *format, char *result,
		int *counter, t_flags *flags)
{
	int count;

	count = 0;
	ft_putstr_fd(result, 1);
	if (format[count] == 'c')
		(*counter) += 1 + flags->n_width;
	else
		(*counter) += ft_strlen(result);
}

void	ft_counter_2(const char *format, int *counter, int *i)
{
	int count;

	count = 0;
	(*counter)++;
	ft_putchar_fd(format[count], 1);
	(*i)++;
}

int		ft_printf(const char *format, ...)
{
	va_list		list;
	int			i;
	char		*result;
	t_flags		flags;
	int			counter;

	i = 0;
	counter = 0;
	va_start(list, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			flags = ft_flag_initializer(flags);
			check_flags(&i, &flags, &format[i], &list);
			result = ft_precision(&format[i], &flags, &list);
			ft_counter_1(&format[i++], result, &counter, &flags);
			free(result);
		}
		else
			ft_counter_2(&format[i], &counter, &i);
	}
	va_end(list);
	return (counter);
}
