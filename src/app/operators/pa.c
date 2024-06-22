/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:35:07 by serferna          #+#    #+#             */
/*   Updated: 2024/06/19 14:58:24 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/**
 * Pushes the top element of stack b to stack a.
 *
 */
void	pa(const t_stacks* stacks)
{
	int	b_value;

	if (stacks->stack_b->size == 0)
		return ;
	b_value = stacks->stack_b->stack[stacks->stack_b->size - 1]->value;
	push_stack(stacks->stack_a, b_value);
	pop_stack(stacks->stack_b);
	ft_putstr_fd("pa\n", 1);
}
