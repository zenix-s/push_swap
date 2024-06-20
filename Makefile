# DIRECTORIES
SRC = $(wildcard ./src/app/**/*.c) ./src/push_swap.c
OBJ = $(SRC:.c=.o)

# VARIABLES
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -f

# LIBRARIES
LIBFT_SRC = ./src/lib/libft
LIBFT = $(LIBFT_SRC)/libft.a

# PROGRAM
NAME = push_swap

$(LIBFT):
	@$(MAKE) -s all -C $(LIBFT_SRC) > /dev/null
	@echo "Libft compiled"

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "Push_swap compiled"

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

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
.DEFAULT_GOAL = all
