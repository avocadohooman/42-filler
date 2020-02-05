# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/19 13:45:47 by gmolin            #+#    #+#              #
#    Updated: 2020/02/05 16:25:08 by gmolin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_RED = \033[1;31m
C_GREEN = \033[1;32m
C_L_GREEN = \033[1;32m
C_BLUE = \033[1;34m
C_L_BLUE = \033[1;34m
C_WHITE = \033[1;37m
C_RES = \033[0m

NAME = gmolin.filler

FLAGS = -Wall -Wextra -Werror -O3

SRCS = 	srcs/initiate_struct.c \
		srcs/piece_mode.c \
		srcs/map_mode.c \
		srcs/tools.c \
		srcs/placing_dispatcher.c \
		srcs/placing_bl.c \
		srcs/placing_tr.c \
		srcs/placing_tl.c \
		srcs/placing_br.c \
		srcs/placing_all.c \
		srcs/strategy_mode.c \
		srcs/returning_piece.c \
		srcs/main.c \
		srcs/tools2.c

OBJS = $(subst .c,.o,$(subst srcs/,,$(SRCS)))

OBJS2 = initiate_struct.o \
		piece_mode.o \
		map_mode.o \
		tools.o \
		tools2.o \
		placing_dispatcher.o \
		placing_bl.o \
		placing_tr.o \
		placing_tl.o \
		placing_br.o \
		placing_all.o \
		strategy_mode.o \
		returning_piece.o \
		main.o 

LIB = ./libftprintf/libftprintf.a

INCL = -I ./includes/ -I ./libftprintf/includes/

all: $(NAME)

$(NAME): libftcreator
	@gcc $(FLAGS) -c $(SRCS) $(INCL)
	@gcc $(FLAGS) $(INCL) $(OBJS) $(LIB) -o $(NAME)
	@echo "$(C_GREEN)[$(C_BLUE)$(NAME)$(C_GREEN) was compiled]$(C_RES)"
	
libftcreator:
	make -C libftprintf

clean:
	rm -f $(OBJS2)
	make clean -C libftprintf

fclean: clean
	rm -f $(NAME)
	make fclean -C libftprintf
	
re: clean all
