#include "../../push_swap.h"
void print_stack(t_stack *stack) {
  int size;

  size = stack->size;
  while (size - 1 >= 0) {
    ft_printf("%d\n", stack->stack[size - 1]);
    size--;
  }
}
