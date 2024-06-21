/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:08:51 by serferna          #+#    #+#             */
/*   Updated: 2024/06/19 20:20:13 by serferna         ###   ########.fr       */
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

	if (is_sorted(stacks->stack_a))
		return ;
	max = find_max(stacks->stack_a);
	min = find_min(stacks->stack_a);
	if (max->index == 0 && min->index == 1)
		sa(stacks);
	else if (max->index == 1)
	{
		rra(stacks);
		if (!is_sorted(stacks->stack_a))
			sa(stacks);
	}
	else if (min->index == 0)
	{
		sa(stacks);
		rra(stacks);
	}
	else
		ra(stacks);
}
