/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:08:51 by serferna          #+#    #+#             */
/*   Updated: 2024/06/19 17:03:07 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// sort three items in descending order
// top of the stack is the smallest item with the index 2
// bottom of the stack is the biggest item with the index 0
void	sort_three(t_stacks *stacks)
{
	t_item	*max;
	t_item	*min;

	max = find_max(stacks->stack_a);
	min = find_min(stacks->stack_a);
	if (max->index == 0 && min->index == 1)
		sa(stacks);
	else if (stacks->stack_a->stack[1]->value == max->value)
	{
		rra(stacks);
		if (stacks->stack_a->stack[1]->value == min->value)
			sa(stacks);
	}
	else if (stacks->stack_a->stack[0]->value == min->value)
	{
		sa(stacks);
		rra(stacks);
	}
	else
		ra(stacks);
}
