#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

// LIBFT
#include "./lib/libft/libft.h"

typedef struct s_stack {
  char id;
  int size;
  int *stack;
} t_stack;


void print_stack(t_stack *stack);
void swap_a(t_stack *a);
void swap_b(t_stack *b);
void swap_ss(t_stack *a, t_stack *b);

#endif
