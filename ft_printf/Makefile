# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dyoung <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 16:10:51 by dyoung            #+#    #+#              #
#    Updated: 2020/11/16 16:11:02 by dyoung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = src/ft_printf.c \
		src/nachalo.c \
		src/type_di.c \
		src/type_ldi.c \
		src/type_lldi.c \
		src/type_hdi.c \
		src/type_x.c \
		src/type_lx.c \
		src/type_llx.c \
		src/type_hx.c \
		src/type_o.c \
		src/type_c.c \
		src/type_s.c \
		src/type_hhdi.c \
		src/type_hhx.c \
		src/type_u.c \
		src/type_p.c \
		src/type_lo.c \
		src/type_llo.c \
		src/type_ho.c \
		src/type_hho.c \
		src/type_lu.c \
		src/type_llu.c \
		src/type_hu.c \
		src/type_hhu.c \
		src/type_f.c \
		src/bonus.c \
		src/distrib.c \
		src/distrib_types.c \
		src/check_flags.c \
		src/type_f2.c \
		src/other.c \
		src/type_lf.c \
		src/type_lf2.c

SURPL_O = src/ft_printf.o \
		src/nachalo.o \
		src/type_di.o \
		src/type_ldi.o \
		src/type_lldi.o \
		src/type_hdi.o \
		src/type_x.o \
		src/type_lx.o \
		src/type_llx.o \
		src/type_hx.o \
		src/type_o.o \
		src/type_c.o \
		src/type_s.o \
		src/type_hhdi.o \
		src/type_hhx.o \
		src/type_u.o \
		src/type_p.o \
		src/type_lo.o \
		src/type_llo.o \
		src/type_ho.o \
		src/type_hho.o \
		src/type_lu.o \
		src/type_llu.o \
		src/type_hu.o \
		src/type_hhu.o \
		src/type_f.o \
		src/bonus.o \
		src/distrib.o \
		src/distrib_types.o \
		src/check_flags.o \
		src/type_f2.o \
		src/other.o \
		src/type_lf.o \
		src/type_lf2.o

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)


clean :
	rm -rf $(SURPL_O) 
	rm -rf $(OBJS)
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean all

