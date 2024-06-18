/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 23:11:18 by serferna          #+#    #+#             */
/*   Updated: 2024/06/18 23:28:56 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	calculate_operations(t_stacks *stacks, t_item item)
{
	int		total_cost;
	t_item	closest;
	t_cost	a_cost;
	t_cost	b_cost;

	closest = find_target(stacks->stack_a, item.value);
	a_cost = calc_cost(stacks->stack_a, closest, TOP);
	b_cost = calc_cost(stacks->stack_b, item, TOP);
	if (a_cost.direction == UP && b_cost.direction == UP)
	{
		if (a_cost.cost > b_cost.cost)
			total_cost = a_cost.cost;
		else
			total_cost = b_cost.cost;
	}
	else if (a_cost.direction == DOWN && b_cost.direction == DOWN)
	{
		if (a_cost.cost > b_cost.cost)
			total_cost = a_cost.cost;
		else
			total_cost = b_cost.cost;
	}
	else
		total_cost = a_cost.cost + b_cost.cost;
	return (total_cost);
}
