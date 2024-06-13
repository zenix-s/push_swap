#include "../../push_swap.h"

/**
 * Pops the top element of the stack.
 * @param stack Pointer to the stack.
 */
void pop(t_stack *stack) {
  int *new_stack;
  int i;

  if (stack->size == 0)
    return;

  new_stack = (int *)malloc((stack->size - 1) * sizeof(int));
  i = 0;
  while (i < stack->size - 1) {
    new_stack[i] = stack->stack[i];
    i++;
  }
  free(stack->stack);
  stack->stack = new_stack;
  stack->size--;
}
