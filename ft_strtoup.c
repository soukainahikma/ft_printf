/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 11:56:00 by shikma            #+#    #+#             */
/*   Updated: 2020/01/07 11:56:04 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strtoup(char *str)
{
	int		i;
	char	*dest;
	size_t	len;

	len = ft_strlen(str);
	i = 0;
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			dest[i] = str[i] - 32;
			i++;
		}
		else
		{
			dest[i] = str[i];
			i++;
		}
	}
	dest[i] = '\0';
	return (dest);
}
