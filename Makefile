NAME = pipex

CC = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDE = -Ilibft
VPATH = src
SRC = pipex.c pipex_utils.c pipex_split.c


OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

LIBFT_FLAGS = -Llibft -lft 
LIBFT = libft.a

all: $(NAME)

$(LIBFT):
	make -C libft
 
$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LIBFT_FLAGS)-o $@

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	
clean:
	rm -rf $(OBJ_DIR)
	make clean -C libft

fclean: 	clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all