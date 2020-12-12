/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:11:47 by shikma            #+#    #+#             */
/*   Updated: 2019/12/10 19:12:08 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		if (n == -2147483648)
			ft_putstr_fd("-2147483648", fd);
		else
		{
			n = n * (-1);
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(n, fd);
		}
	}
	else
	{
		if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putchar_fd(n % 10 + '0', fd);
		}
		else
			ft_putchar_fd(n + '0', fd);
	}
}
