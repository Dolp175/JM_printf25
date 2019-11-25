# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jomartin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 09:44:20 by jomartin          #+#    #+#              #
#    Updated: 2019/11/25 14:27:55 by jomartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_isascii.c	ft_memcpy.c	ft_strlcpy.c ft_toupper.c ft_atoi.c	ft_isdigit.c ft_memmove.c ft_strlen.c ft_bzero.c ft_isprint.c ft_memset.c ft_strncmp.c ft_calloc.c ft_memccpy.c ft_strchr.c ft_strnstr.c ft_isalnum.c ft_memchr.c ft_strdup.c ft_strrchr.c ft_isalpha.c ft_memcmp.c ft_strlcat.c ft_tolower.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_freemem.c ft_printf.c reset_struct.c print_valid.c print_unsigned.c print_string.c print_pointer.c print_number2.c print_number.c print_hexa.c print_char.c ft_printf_utils.c ft_check_arg.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

CC = cc

RM = rm -f

FLAGS = -Wall -Werror -Wextra

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

all:		$(NAME)

clean:
			${RM} ${OBJS}

fclean: 	
			${RM} ${NAME}
re:			fclean all

.PHONY:		all clean fclean re
