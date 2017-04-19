NAME = lem_in

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

SRC_DIR = ./src/

PATH_HD = -I includes/

SRCS = main.c save_input.c get_map.c fill_start.c travel.c \
       name_ants.c

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
