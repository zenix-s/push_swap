/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:36:15 by serferna          #+#    #+#             */
/*   Updated: 2024/06/18 15:22:59 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

// LIBFT
#include "./lib/libft/libft.h"

#define INT_MAX 2147483647
#define INT_MIN -2147483648

typedef struct s_item {
  int value;
  int index;
} t_item;

typedef struct s_stack {
  char id;
  int size;
  t_item *stack;
} t_stack;

typedef struct s_stacks {
  t_stack *stack_a;
  t_stack *stack_b;
} t_stacks;

typedef enum e_direction { UP, DOWN } t_direction;

typedef struct s_cost {
  int cost;
  t_direction direction;
} t_cost;

typedef struct s_total_cost {
  t_cost a_cost;
  t_cost b_cost;
  int total_cost;
} t_total_cost;

typedef enum e_cost_type { TOP, BOTTOM } t_cost_type;

typedef struct s_operation {
  int n_ra;
  int n_rb;
  int n_rr;
  int n_rra;
  int n_rrb;
  int n_rrr;
  int total;
} t_operation;

typedef struct s_sort_data {
  t_item *sorted;
  int size;
  t_item pivot;
  t_item min;
  t_item max_1;
  t_item max_2;
  t_item max_3;
  t_item max_4;
  t_item max_5;
} t_sort_data;

// Error handling
void free_stack(t_stack *stack);
void error(t_stacks *stacks);

// Stack
t_stack *init_stack(char id);
void print_stack(t_stack *stack);
void load_stack(t_stacks *stacks, int argc, char **argv);
t_bool find_dup(t_stack *stack, int item);
t_bool process_item(char *str, int *item);

// Stack generic operators
void pop_stack(t_stack *stack);
void push_stack(t_stack *stack, int element);
void swap_stack(t_stack *stack);
void rotate_stack(t_stack *stack);
void reverse_rotate_stack(t_stack *stack);

// Stack operators
void sa(t_stacks *stacks);
void sb(t_stacks *stacks);
void ss(t_stacks *stacks);
void pa(t_stacks *stacks);
void pb(t_stacks *stacks);
void ra(t_stacks *stacks);
void rb(t_stacks *stacks);
void rr(t_stacks *stacks);
void rra(t_stacks *stacks);
void rrb(t_stacks *stacks);
void rrr(t_stacks *stacks);

// Sort utils
t_item find_min(t_stack *stack);
t_item find_max(t_stack *stack);
t_bool is_sorted(t_stack *stack);
void top_item(t_stacks *stacks, char stack_id, t_item item);
void bottom_item(t_stacks *stacks, char stack_id, t_item item);
t_cost calc_cost(t_stack *stack, t_item item, t_cost_type cost_type);
// Sorting
int ft_sort(t_stacks *stacks);
void sort_two(t_stacks *stacks);
void sort_three(t_stacks *stacks);
void sort_four(t_stacks *stacks);
void sort_five(t_stacks *stacks);
t_item *bubble_sort(t_item *stack, int size);

#endif
