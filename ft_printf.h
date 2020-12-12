/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 11:52:02 by shikma            #+#    #+#             */
/*   Updated: 2020/01/08 17:36:14 by shikma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct	s_flags
{
	int width;
	int precision;
	int sign;
	int n_width;
	int n_precision;
	int zero;
	int minus;
}				t_flags;

int				ft_printf(const char *format, ...);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_itoa(int n);
char			*ft_uitoa(unsigned int n);
char			*ft_hexadecimal(unsigned int n);
char			*ft_strtoup(char *str);
size_t			ft_strlen(const char *str);
char			*ft_address(long unsigned int address);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strdup(const char *src);
char			*ft_long_hexadecimal(long unsigned int n);
int				ft_atoi(const char *str);
char			*ft_int_precision(t_flags *flags, int d);
int				ft_isdigit(int c);
char			*ft_string_precision(t_flags *flags, char *str);
char			*ft_uint_precision(t_flags *flags, unsigned int u);
char			*ft_hex_precision(t_flags *flags, unsigned int h);
char			*ft_width(t_flags *flags, char *str);
char			*ft_only_int(t_flags *flags, int integer);
t_flags			ft_flag_initializer(t_flags format);
void			ft_skip_char(const char *format, int *j, int *i);
void			check_flags(int *i, t_flags *flags,
		const char *format, va_list *ap);
char			*ft_only_char(t_flags *flags, int c);
int				ft_isprint(int c);
char			*ft_percent(t_flags *flags);
char			*ft_only_string(char *str);
#endif
