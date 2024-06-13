#include "../../push_swap.h"

t_stack *init_stack() {
  t_stack *stack;

  stack = (t_stack *)malloc(sizeof(t_stack));
  stack->stack = NULL;
  return stack;
}
