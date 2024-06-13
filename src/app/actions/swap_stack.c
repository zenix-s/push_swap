#include "../../push_swap.h"

/**
 * Swaps the top two elements of the stack.
 * @param stack Pointer to the stack.
 */
void swap(t_stack *stack) {
  int tmp;
  if (stack->size < 2)
    return;
  tmp = stack->stack[stack->size - 1];
  stack->stack[stack->size - 1] = stack->stack[stack->size - 2];
  stack->stack[stack->size - 2] = tmp;
}
