# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/06 12:56:11 by gmolin            #+#    #+#              #
#    Updated: 2020/01/23 13:03:32 by gmolin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libftprintf.a

FLAGS = -Wall -Wextra -Werror

LIBFT_FOLDER = ./libft/

LIB = ./libft/libft.a

LIB_OBJ = ./libft/*.o

SRCS1 = ft_printf/srcs/ft_printf.c ft_printf/srcs/conversion_distributor.c \
		ft_printf/srcs/modifier_setup.c ft_printf/srcs/c_conversion.c ft_printf/srcs/helper_print.c \
		ft_printf/srcs/s_conversion.c ft_printf/srcs/p_conversion.c ft_printf/srcs/id_conversion.c \
		ft_printf/srcs/helper_converter.c ft_printf/srcs/o_conversion.c ft_printf/srcs/u_conversion.c \
		ft_printf/srcs/x_conversion.c ft_printf/srcs/helper_swap.c ft_printf/srcs/f_conversion.c

####OBJS = $(subst .c,.o,$(subst ft_printf/srcs//,,$(SRCS1)))

OBJS =  ./ft_printf.o ./conversion_distributor.o \
		./modifier_setup.o ./c_conversion.o ./helper_print.o \
		./s_conversion.o ./p_conversion.o ./id_conversion.o \
		./helper_converter.o ./o_conversion.o ./u_conversion.o \
		./x_conversion.o ./helper_swap.o ./f_conversion.o

INCL = -I ./includes/ -I ./libft/includes/

all: $(NAME)

$(NAME): $(SRCS1)
	@make -s -C $(LIBFT_FOLDER)
	@cp $(LIB) ./$(NAME)
	@gcc $(FLAGS) $(INCLUDES) -c $(SRCS1)
	@ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	
clean:
	@rm -f $(OBJS) $(LIB_OBJ)
	@make -s clean -C libft

fclean: clean
	@rm -f $(NAME)
	@make -s fclean -C libft
	
re: fclean all

.PHONY: clean fclean re all