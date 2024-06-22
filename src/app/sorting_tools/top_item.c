/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_item.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:54:28 by serferna          #+#    #+#             */
/*   Updated: 2024/06/19 15:19:31 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	calculate_cost(const t_stack* stack, const t_item* item, int *cost_up,
	                          int *cost_down)
{
	*cost_up = (stack->size - 1) - item->index;
	*cost_down = item->index + 1;
}

/**
 * Moves the item to the top of the stack
 *
 */
void	top_item(const t_stacks *stacks, const char stack_id, const t_item* item)
{
	int	cost_up;
	int	cost_down;

	if (stack_id == 'a')
		calculate_cost(stacks->stack_a, item, &cost_up, &cost_down);
	else
		calculate_cost(stacks->stack_b, item, &cost_up, &cost_down);
	if (cost_up <= cost_down)
	{
		while (cost_up-- > 0)
		{
			if (stack_id == 'a')
				ra(stacks);
			else
				rb(stacks);
		}
		return ;
	}
	while (cost_down-- > 0)
	{
		if (stack_id == 'a')
			rra(stacks);
		else
			rrb(stacks);
	}
}
