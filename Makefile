# DIRECTORIES
MAIN_SRC = ./src/push_swap.c
SRC = $(wildcard ./src/app/**/*.c)

# VARIABLES
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# LIBRARIES
LIBFT_SRC = ./src/lib/libft
LIBFT = $(LIBFT_SRC)/libft.a

# PROGRAM
NAME = push_swap

$(LIBFT):
	@$(MAKE) -s all -C $(LIBFT_SRC) > /dev/null
	@echo "Libft compiled"

$(NAME): $(LIBFT)
	@$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(MAIN_SRC) -o $(NAME)
	@echo "Push_swap compiled"

all: $(NAME)

clean:
	@$(RM) $(OBJ)
	@$(MAKE) -s clean -C $(LIBFT_SRC)
	@$(RM) $(Ma)
	@echo "Objects removed"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -s fclean -C $(LIBFT_SRC)
	@echo "Push_swap removed"

re: fclean all

.PHONY: all clean fclean re