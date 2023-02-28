NAME = pipex
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = pipex.c pipex_utils.c pipex_split.c
OBJ = $(SRC:.c=.o)
LIBFT = libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C ../libft

$(NAME): $(SRC)
	$(CC) $(SRC) -lft -I../libft -L../libft -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@
	
clean:
	rm -rf $(OBJ)
	make clean -C ../libft

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)
	make fclean -C ../libft

re: fclean all