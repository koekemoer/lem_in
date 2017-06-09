# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkoekemo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/17 13:54:26 by lkoekemo          #+#    #+#              #
#    Updated: 2017/05/17 13:54:27 by lkoekemo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g -g3

SRC_DIR = ./src/

PATH_HD = -I includes/

SRCS = main.c save_input.c get_map.c fill_start.c travel.c \
       name_ants.c travel_functions.c free_stuff.c display.c

SRC = $(addprefix $(SRC_DIR), $(SRCS))

OBJ = $(SRCS:.c=.o)

$(NAME):
	@echo "Compiling..."
	@make re -C libft/
	@$(CC) $(CFLAGS) $(PATH_HD) -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) -L libft/ -lft
	@echo "Compilation successful\n"

all : $(NAME)

clean:
	@echo "Cleaning..."
	@rm -f $(OBJ)
	@make -C libft/ clean
	@echo "Cleaned!\n"

fclean:
	@echo "F-Cleaning..."
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "F-Cleaned!\n"

re: fclean all
