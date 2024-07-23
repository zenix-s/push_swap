# DIRECTORIES
SRC =	./src/push_swap.c \
		./src/app/case_sort/bubble_sort.c \
		./src/app/case_sort/sort_five.c \
		./src/app/case_sort/sort_four.c \
		./src/app/case_sort/sort_three.c \
		./src/app/case_sort/sort_two.c \
		./src/app/error_handlers/error.c \
		./src/app/operators/pa.c \
		./src/app/operators/pb.c \
		./src/app/operators/ra.c \
		./src/app/operators/rb.c \
		./src/app/operators/rr.c \
		./src/app/operators/rra.c \
		./src/app/operators/rrb.c \
		./src/app/operators/rrr.c \
		./src/app/operators/sa.c \
		./src/app/operators/sb.c \
		./src/app/operators/ss.c \
		./src/app/operators/generic_operators/pop_stack.c \
		./src/app/operators/generic_operators/push_stack.c \
		./src/app/operators/generic_operators/reverse_rotate_stack.c \
		./src/app/operators/generic_operators/rotate_stack.c \
		./src/app/operators/generic_operators/swap_stack.c \
		./src/app/parse_args/is_invalid.c \
		./src/app/parse_args/load_stack.c \
		./src/app/parse_args/process_arg.c \
		./src/app/sort/is_sorted.c \
		./src/app/sort/init_sort_data.c \
		./src/app/sort/ft_sort.c \
		./src/app/sort/sort_operations/top_item.c \
		./src/app/sort/sort_operations/push_to_target.c \
		./src/app/sort/sort_cost_operation/cost_top.c \
		./src/app/sort/sort_cost_operation/calculate_operation.c \
		./src/app/sort/sort_tools/find_max.c \
		./src/app/sort/sort_tools/find_min.c \
		./src/app/sort/sort_tools/is_big_five.c \
		./src/app/sort/sort_tools/find_target.c \
		./src/app/stack/end_program.c \
		./src/app/stack/find_duplicate_stack.c \
		./src/app/stack/init_stack.c \

OBJ = $(SRC:.c=.o)

# VARIABLES
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

# LIBRARIES
LIBFT_SRC = ./src/lib/libft

LIB = $(LIBFT_SRC)/libft.a

# PROGRAM
NAME = push_swap

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

libft:
	@$(MAKE) -s all -C $(LIBFT_SRC)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

all: libft $(NAME)


clean:
	@$(RM) $(OBJ)
	@$(MAKE) -s clean -C $(LIBFT_SRC)

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -s fclean -C $(LIBFT_SRC)

re: fclean all

.PHONY: all libft clean fclean re
.DEFAULT_GOAL = all
