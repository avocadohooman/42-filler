# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/19 13:45:47 by gmolin            #+#    #+#              #
#    Updated: 2020/01/25 14:15:22 by gmolin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gmolin.filler

FLAGS = -Wall -Wextra -Werror

SRCS1 = ./srcs/main.c ./srcs/map_mode.c

OBJS = $(subst .c,.o,$(subst srcs/,,$(SRCS1)))

LIB = -L./libftprintf -lft

INCL = -I ./srcs -I ./libftprintf/includes/

all: libftcreator
	gcc $(FLAGS) -c $(SRCS1) $(INCL)
	gcc $(FLAGS) $(INCL) $(OBJS) $(LIB) -o $(NAME)

libftcreator:
	make -C libftprintf

clean:
	rm -f $(OBJS)
	make clean -C libftprintf

fclean: clean
	rm -f $(NAME)
	make fclean -C libftprintf
	
re: clean all
