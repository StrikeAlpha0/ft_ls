# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msharpe <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/15 23:30:51 by msharpe           #+#    #+#              #
#    Updated: 2018/07/16 13:05:34 by msharpe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILENAMES	= ft_ls.c order.c ft_fullinfo.c ft_listdirectory.c mergesort.c

FILENAMES2	= ft_atoi.c ft_bzero.c ft_numlen.c ft_print_hex.c ft_print_hexup.c\
			  	ft_print_octal.c ft_printf.c ft_putchar.c ft_putnbr.c\
				ft_putnbrup.c ft_putstr.c initializefunc.c printfconvert.c\
				printfflags.c printfnumbers.c printfwriter.c printfsystem.c\
				ft_frontloadflag.c ft_midloadflag.c ft_backloadflag.c\
				printfspecify.c ft_strstr.c ft_strlen.c search_width.c\
				printfmulti.c ft_putstrup.c ft_cryptoputstr.c ft_wstrlen.c\
				ft_putstrrot13.c ft_wput_strup.c ft_wputstr.c ft_base64.c

FILENAMES3	= ft_strcmp.c ft_strdup.c ft_strjoin.c ft_strcpy.c ft_strnew.c\
			  ft_memalloc.c

NAME		= ft_ls
NAME2		= ft_ls.a
CC			= gcc
SRCS		= $(addprefix srcs/,$(FILENAMES))
PRNTF		= $(addprefix includes/libftls/,$(FILENAMES2))
LIBFT		= $(addprefix includes/libftls/libft/,$(FILENAMES3))
OBJS		= $(FILENAMES:.c=.o)
OBJS2		= $(addprefix objects/,$(OBJS))
CFLAGS		= -Wall -Werror -Wextra -o
INCLS		= includes

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(NAME) $(SRCS) -I includes $(PRNTF) -I includes $(LIBFT)

clean:
	rm -f $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all
