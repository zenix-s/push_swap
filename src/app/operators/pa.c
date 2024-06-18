/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:35:07 by serferna          #+#    #+#             */
/*   Updated: 2024/06/14 17:35:42 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/**
 * Pushes the top element of stack b to stack a.
 *
 */
void	pa(t_stacks *stacks)
{
	if (stacks->stack_b->size == 0)
		return ;
	push_stack(stacks->stack_a, stacks->stack_b->stack[stacks->stack_b->size
		- 1].value);
	pop_stack(stacks->stack_b);
	ft_printf("pa\n");
}
