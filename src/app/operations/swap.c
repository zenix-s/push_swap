#include "../../push_swap.h"

static void swap(t_stack *stack) {
  int tmp;
  if (stack->size < 2)
    return;
  tmp = stack->stack[stack->size - 1];
  stack->stack[stack->size - 1] = stack->stack[stack->size - 2];
  stack->stack[stack->size - 2] = tmp;
}

void swap_a(t_stack *a) {
  swap(a);
  ft_printf("s%c\n", a->id);
}

void swap_b(t_stack *b) {
  swap(b);
  ft_printf("s%c\n", b->id);
}

void swap_ss(t_stack *a, t_stack *b) {
  swap(a);
  swap(b);
  ft_printf("ss\n");
}
