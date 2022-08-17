# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/27 10:44:06 by ashulha           #+#    #+#              #
#    Updated: 2020/11/16 15:59:24 by dyoung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
GNL = gnl/get_next_line.c
FLAG = -Wall -Wextra -Werror
CC = gcc

SRC = src/add_rooms.c src/add_ways.c src/alg.c src/bfs.c src/create_tab.c \
	  src/dfs.c src/distrib.c src/exit.c src/free_alg.c src/init_alg.c \
	  src/main.c src/print_parser.c src/result_show.c src/tools_alg.c \
	  src/tools_for_read.c src/utils_parser.c src/work_list.c src/work_ways.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJ) src/lem_in.h
		$(CC) $(FLAG) $(LIBFT) $(PRINTF) $(GNL) $(OBJ) -o $(NAME)

$(LIBFT):
	@make -C libft/

$(PRINTF):
	@make -C ft_printf/

clean:
		@make clean -C libft/
		@make clean -C ft_printf/
		rm -f $(OBJ)

fclean: clean
		@make fclean -C libft/
		@make fclean -C ft_printf/
		rm -f $(NAME)

re: fclean all
