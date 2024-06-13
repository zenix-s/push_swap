#include "../../push_swap.h"

void error(t_stack *stack_a, t_stack *stack_b) {
  free_stack(stack_a);
  free_stack(stack_b);
  ft_printf("Error\n");
  exit(1);
}
