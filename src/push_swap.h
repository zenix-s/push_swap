/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 21:24:18 by serferna          #+#    #+#             */
/*   Updated: 2024/06/22 20:04:32 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// LIBFT
# include "./lib/libft/libft.h"

# define INT_MAX 2147483647

typedef struct s_item
{
	int			value;
	int			index;
}				t_item;

typedef struct s_stack
{
	char		id;
	int			size;
	t_item		**stack;
	int			allocated;
}				t_stack;

typedef struct s_stacks
{
	t_stack		*stack_a;
	t_stack		*stack_b;
}				t_stacks;

typedef enum e_direction
{
	UP,
	DOWN
}				t_direction;

typedef struct s_cost
{
	int			cost;
	t_direction	direction;
}				t_cost;

typedef struct s_sort_data
{
	int			size;
	int			pivot;
	int			max_1;
	int			max_2;
	int			max_3;
	int			max_4;
	int			max_5;
}				t_sort_data;

// Program related
void			end_program(t_stacks *stacks);
void			free_stack(t_stack *stack);

// Error handling
void			error(t_stacks *stacks);

// Stack
t_bool			init_stack(const char id, int stack_size, t_stack **stack);
t_bool			find_dup(const t_stack *stack, int item);

// Parse arguments
t_bool			is_invalid_arg(const char *str);
t_bool			process_item(const char *str, int *item);
void			load_stack(t_stacks *stacks, int argc, char **argv);

// Stack generic operators
void			pop_stack(t_stack *stack);
void			push_stack(t_stack *stack, const int element);
void			swap_stack(const t_stack *stack);
void			rotate_stack(const t_stack *stack);
void			reverse_rotate_stack(const t_stack *stack);

// Stack operators
void			sa(const t_stacks *stacks);
void			sb(const t_stacks *stacks);
void			ss(const t_stacks *stacks);
void			pa(const t_stacks *stacks);
void			pb(const t_stacks *stacks);
void			ra(const t_stacks *stacks);
void			rb(const t_stacks *stacks);
void			rr(const t_stacks *stacks);
void			rra(const t_stacks *stacks);
void			rrb(const t_stacks *stacks);
void			rrr(const t_stacks *stacks);

// Sort tools
t_item			*find_min(const t_stack *stack);
t_item			*find_max(const t_stack *stack);
t_bool			is_sorted(const t_stack *stack);
void			top_item(const t_stacks *stacks, char id, const t_item *item);
t_cost			cost_top(const t_stack *stack, const t_item *item);
int				*bubble_sort_init_stack(t_stacks *stacks);

// Sort by size
void			sort_two(const t_stacks *stacks);
void			sort_three(const t_stacks *stacks);
void			sort_four(const t_stacks *stacks);
void			sort_five(const t_stacks *stacks);

// Sort array of items
int				*bubble_sort(int *stack, int size);

// Sort
int				ft_sort(t_stacks *stacks);

// Sort Utils
t_sort_data		*init_sort_data(t_stacks *stacks);
t_bool			is_big_five(const t_sort_data *data, const int value);
t_item			*find_target(const t_stack *stack, const int value);
int				calculate_operation(const t_stacks *stacks, const t_item *item);
void			push_to_target(const t_stacks *stacks, const t_item *item);

#endif
