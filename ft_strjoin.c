/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 14:05:06 by shikma            #+#    #+#             */
/*   Updated: 2020/01/06 21:39:24 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char				*s3;
	unsigned int		len;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	len = 0;
	s3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s3 == NULL)
		return (NULL);
	while (*s1)
		s3[len++] = *(s1++);
	while (*s2)
		s3[len++] = *(s2++);
	s3[len] = '\0';
	return (s3);
}
