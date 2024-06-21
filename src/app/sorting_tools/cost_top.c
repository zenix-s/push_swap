/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:54:00 by serferna          #+#    #+#             */
/*   Updated: 2024/06/19 15:14:52 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_cost	cost_top(t_stack *stack, t_item *item)
{
	t_cost	cost;
	int		cost_up;
	int		cost_down;

	cost_up = (stack->size - 1) - item->index;
	cost_down = item->index + 1;
	if (cost_up <= cost_down)
	{
		cost.cost = cost_up;
		cost.direction = UP;
		return (cost);
	}
	cost.cost = cost_down;
	cost.direction = DOWN;
	return (cost);
}
