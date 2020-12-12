# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shikma <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/08 11:48:43 by shikma            #+#    #+#              #
#    Updated: 2020/01/07 11:59:45 by shikma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
AR = ar rcs
FLAGS = -Wall -Wextra -Werror
SRC  = ft_putstr_fd.c\
	   ft_putnbr_fd.c\
	   ft_putchar_fd.c\
	   ft_printf.c\
	   ft_itoa.c\
	   ft_uitoa.c\
	   ft_hexadecimal.c\
	   ft_long_hexadecimal.c\
	   ft_strtoup.c\
	   ft_strlen.c\
	   ft_address.c\
	   ft_strdup.c\
	   ft_strjoin.c\
	   ft_atoi.c\
	   ft_isdigit.c\
	   ft_int_precision.c\
	   ft_string_precision.c\
	   ft_uint_precision.c\
	   ft_hex_precision.c\
	   ft_width.c\
	   ft_only_int.c\
	   ft_flag_initializer.c\
	   ft_skip_char.c\
	   ft_check_flags.c\
	   ft_only_char.c\
	   ft_isprint.c\
	   ft_percent.c\
	   ft_only_string.c

HEADERS = ft_printf.h
OBJECT = $(SRC:.c=.o)

$(NAME): $(OBJECT)
	@$(AR) $(NAME) $(OBJECT)

%.o: %.c
	@gcc $(FLAGS) -I $(HEADERS)  -o $@ -c $<

all: $(NAME)

clean:
	@rm -f $(OBJECT)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)

