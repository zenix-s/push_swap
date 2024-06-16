/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:36:15 by serferna          #+#    #+#             */
/*   Updated: 2024/06/17 01:19:27 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// LIBFT
# include "./lib/libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_item
{
  int	value;
  int	index;
}			t_item;

typedef struct s_stack
{
	char	id;
	int		size;
  t_item *stack;
}			t_stack;

typedef struct s_stacks
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}			t_stacks;

// Error handling
void		free_stack(t_stack *stack);
void		error(t_stacks *stacks);

// Stack
t_stack		*init_stack(char id);
void		print_stack(t_stack *stack);
void		load_stack(t_stacks *stacks, int argc, char **argv);
t_bool	find_dup(t_stack *stack, int item);
t_bool	process_item(char *str, int *item);

// Stack generic operators
void		pop_stack(t_stack *stack);
void		push_stack(t_stack *stack, int element);
void		swap_stack(t_stack *stack);
void		rotate_stack(t_stack *stack);
void		reverse_rotate_stack(t_stack *stack);

// Stack operators
void		sa(t_stacks *stacks);
void		sb(t_stacks *stacks);
void		ss(t_stacks *stacks);
void		pa(t_stacks *stacks);
void		pb(t_stacks *stacks);
void		ra(t_stacks *stacks);
void		rb(t_stacks *stacks);
void		rr(t_stacks *stacks);
void		rra(t_stacks *stacks);
void		rrb(t_stacks *stacks);
void		rrr(t_stacks *stacks);

// Sorting
int ft_sort(t_stacks *stacks);
// void insertion_sort(t_stacks *stacks);

#endif
