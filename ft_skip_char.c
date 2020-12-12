/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 12:49:58 by shikma            #+#    #+#             */
/*   Updated: 2020/01/08 17:37:54 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_skip_char(const char *format, int *j, int *i)
{
	int		count;
	char	c;

	count = 0;
	if (format[count] == '-' || format[count] == '0' || format[count] == '*' ||
			format[count] == '.')
	{
		c = format[count];
		while (format[count] == c || (format[count] == '0' && c == '.'))
		{
			count++;
			(*j)++;
			(*i)++;
		}
		return ;
	}
	while (ft_isdigit(format[count]))
	{
		count++;
		(*j)++;
		(*i)++;
	}
}
