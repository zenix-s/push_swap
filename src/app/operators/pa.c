
#include "../../push_swap.h"

/**
 * Pushes the top element of stack b to stack a.
 *
 */
void pa(t_stack *stack_b, t_stack *stack_a) {
  if (stack_b->size == 0)
    return;

  push(stack_a, stack_b->stack[stack_b->size - 1]);
  pop(stack_b);

  ft_printf("pa\n");
}
