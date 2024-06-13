#include "push_swap.h"
#include "lib/libft/libft.h"


int main(void) {
  int i;
  t_stack *a;
  t_stack *b;

  a = (t_stack *)malloc(sizeof(t_stack));
  b = (t_stack *)malloc(sizeof(t_stack));

  a->id = 'a';
  b->id = 'b';

  a->size = 5;
  a->stack = (int *)malloc(a->size * sizeof(int));
  i = 0;
  while(i < a->size)
  {
    a->stack[i] = i;
    i++;
  }


  b->size = 0;
  b->stack = NULL;

  ft_printf("Stack A:\n");
  print_stack(a);

  ft_printf("-------------\n");

  sa(a);
  ft_printf("Stack A:\n");
  print_stack(a);

  free_stack(a);
  free_stack(b);
  return 0;
}
