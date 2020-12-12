/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_initializer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 21:15:47 by shikma            #+#    #+#             */
/*   Updated: 2020/01/04 16:55:59 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_flag_initializer(t_flags format)
{
	format.width = 0;
	format.precision = 0;
	format.sign = 0;
	format.n_width = 0;
	format.n_precision = 0;
	format.zero = 0;
	format.minus = 0;
	return (format);
}
