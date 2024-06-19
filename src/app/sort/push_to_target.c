/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_target.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 23:12:55 by serferna          #+#    #+#             */
/*   Updated: 2024/06/19 17:36:30 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	execute_rotation(t_stacks *stacks, t_cost a_cost, t_cost b_cost)
{
	while ((a_cost.direction == UP && b_cost.direction == UP) && (a_cost.cost
			&& b_cost.cost))
	{
		rr(stacks);
		a_cost.cost--;
		b_cost.cost--;
	}
	while ((a_cost.direction == DOWN && b_cost.direction == DOWN)
		&& (a_cost.cost && b_cost.cost))
	{
		rrr(stacks);
		a_cost.cost--;
		b_cost.cost--;
	}
	while (a_cost.direction == UP && a_cost.cost--)
		ra(stacks);
	while (b_cost.direction == UP && b_cost.cost--)
		rb(stacks);
	while (a_cost.direction == DOWN && a_cost.cost--)
		rra(stacks);
	while (b_cost.direction == DOWN && b_cost.cost--)
		rrb(stacks);
}

// move the item at the top of b to the target position in a
void	push_to_target(t_stacks *stacks, t_item *item)
{
	t_item	*target;
	t_cost	a_cost;
	t_cost	b_cost;

	target = find_target(stacks->stack_a, item->value);
	a_cost = calc_cost(stacks->stack_a, target, TOP);
	b_cost = calc_cost(stacks->stack_b, item, TOP);

  // ft_printf("itemvl: %d\n", item->value);
  // ft_printf("target: %d\n", target->value);
	execute_rotation(stacks, a_cost, b_cost);
	pa(stacks);
}
