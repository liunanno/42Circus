# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nliu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 15:30:31 by nliu              #+#    #+#              #
#    Updated: 2023/06/08 17:03:40 by nliu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRC	= ft_printf.c	\
	  ft_putchar_pf.c	\
	  ft_putstr_pf.c	\
	  ft_putnbr_pf.c	\
	  ft_putuint_pf.c	\
	  ft_puthex_pf.c	\
	  ft_putptr_pf.c	\
	  ft_aux_pf.c	\

OBJS = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = ar crs

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
