NAME = lem_in

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

SRC_DIR = ./src/

PATH_HD = -I includes/

SRCS = main.c save_input.c

SRC = $(addprefix $(SRC_DIR), $(SRCS))

OBJ = $(SRCS:.c=.o)

$(NAME):
	@echo "Compiling..."
	@make re -C libft/
	@$(CC) $(CFLAGS) $(PATH_HD) -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) -L libft/ -lft
	@echo "Compilation successful"

all : $(NAME)

clean:
	@echo "Cleaning..."
	@rm -f $(OBJ)
	@make -C libft/ clean
	@echo "Cleaned!"

fclean:
	@echo "F-Cleaning..."
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "F-Cleaned!"

re: fclean all
