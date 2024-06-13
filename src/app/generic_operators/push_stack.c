#include "../../push_swap.h"

/**
 * Pushes the top element of stack b to stack a.
 * @param stack Pointer to the stack.
 * @param element Element to push.
 */
void push(t_stack *stack, int element) {
  int *new_stack;
  int i;

  new_stack = (int *)malloc((stack->size + 1) * sizeof(int));
  i = 0;
  while (i < stack->size) {
    new_stack[i] = stack->stack[i];
    i++;
  }
  new_stack[i] = element;
  free(stack->stack);
  stack->stack = new_stack;
  stack->size++;
}
