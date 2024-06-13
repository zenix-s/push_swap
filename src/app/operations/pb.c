#include "../../push_swap.h"

void pb(t_stack *stack_a, t_stack *stack_b) {
  if (stack_a->size == 0)
    return;

  push(stack_b, stack_a->stack[stack_a->size - 1]);
  pop(stack_a);

  ft_printf("pb\n");
}
