#include "../../push_swap.h"

void error(char *message, t_stack *stack_a, t_stack *stack_b) {
  free_stack(stack_a);
  free_stack(stack_b);
  ft_printf("%s\n", message);
  exit(1);
}
