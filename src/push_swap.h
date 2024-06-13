#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

// LIBFT
#include "./lib/libft/libft.h"

typedef struct s_stack {
  char id;
  int size;
  int *stack;
} t_stack;

// Error handling
void free_stack(t_stack *stack);
void error(char *message, t_stack *stack_a, t_stack *stack_b);

// Stack generic operations
void pop(t_stack *stack);
void push(t_stack *stack, int element);
void swap(t_stack *stack);
void rotate(t_stack *stack);
void reverse_rotate(t_stack *stack);
void print_stack(t_stack *stack);

// Stack operations
void sa(t_stack *stack_a);
void sb(t_stack *stack_b);
void ss(t_stack *stack_a, t_stack *stack_b);
void pa(t_stack *stack_b, t_stack *stack_a);
void pb(t_stack *stack_a, t_stack *stack_b);
void ra(t_stack *stack_a);
void rb(t_stack *stack_b);
void rr(t_stack *stack_a, t_stack *stack_b);
void rra(t_stack *stack_a);
void rrb(t_stack *stack_b);
void rrr(t_stack *stack_a, t_stack *stack_b);

#endif
