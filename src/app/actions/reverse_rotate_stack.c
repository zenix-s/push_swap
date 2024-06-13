#include "../../push_swap.h"

/**
 * Reverses the stack. The last element becomes the first, the second to last
 * @param stack Pointer to the stack.
 */
void reverse_rotate(t_stack *stack) {
  int tmp;
  int i;

  if (stack->size < 2)
    return;
  tmp = stack->stack[0];
  i = 0;
  while (i < stack->size - 1) {
    stack->stack[i] = stack->stack[i + 1];
    i++;
  }
  stack->stack[stack->size - 1] = tmp;
}
