/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 21:28:38 by shikma            #+#    #+#             */
/*   Updated: 2020/01/07 12:11:57 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_address(long unsigned int address)
{
	char *result;
	char *ptr;
	char *tmp;

	ptr = ft_strdup("0x");
	tmp = ft_long_hexadecimal(address);
	result = ft_strjoin(ptr, tmp);
	free(tmp);
	free(ptr);
	return (result);
}
