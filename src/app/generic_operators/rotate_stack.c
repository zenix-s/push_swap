#include "../../push_swap.h"

/**
 * Rotates the stack. The top element becomes the bottom element.
 * @param stack Pointer to the stack.
 */
void rotate(t_stack *stack) {
  int tmp;
  int i;

  if (stack->size < 2)
    return;
  tmp = stack->stack[stack->size - 1];
  i = stack->size - 1;
  while (i > 0) {
    stack->stack[i] = stack->stack[i - 1];
    i--;
  }
  stack->stack[0] = tmp;
}
