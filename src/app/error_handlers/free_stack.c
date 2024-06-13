#include "../../push_swap.h"

void free_stack(t_stack *stack) {
  if (stack->stack != NULL)
    free(stack->stack);
  free(stack);
}
