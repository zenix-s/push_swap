#include "push_swap.h"

int main(int argc, char **argv) {

  t_stacks *stacks;

  stacks = (t_stacks *)malloc(sizeof(t_stacks));

  stacks->stack_a = init_stack();
  stacks->stack_b = init_stack();

  load_stack(stacks, argc, argv);

  ft_printf("Stack A:\n");
  print_stack(stacks->stack_a);

  ft_printf("-------------\n");

  sa(stacks->stack_a);
  ft_printf("Stack A:\n");
  print_stack(stacks->stack_a);

  free_stack(stacks->stack_a);
  free_stack(stacks->stack_b);
  free(stacks);
  return 0;
}
