NAME = pipex
CC = cc
CFLAGS = -Wall -Werror -Wextra
VPATH = src
SRC = pipex.c pipex_utils.c pipex_split.c
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
LIBFT = libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft
 
$(NAME): $(OBJ)
	$(CC) $(OBJ) -lft -Ilibft -Llibft -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -rf $(OBJ)
	make clean -C libft

fclean: 	clean
	rm -rf $(NAME) $(NAME_BONUS)
	make fclean -C libft

re: fclean all