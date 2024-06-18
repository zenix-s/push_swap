/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:54:00 by serferna          #+#    #+#             */
/*   Updated: 2024/06/17 23:54:04 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
t_cost calc_cost(t_stack *stack, t_item item, t_cost_type cost_type) {
  t_cost cost;
  int cost_up;
  int cost_down;

  if (cost_type == TOP) {
    cost_up = (stack->size - 1) - item.index;
    cost_down = item.index + 1;
  } else {
    cost_up = (stack->size - 1) - item.index + 1;
    cost_down = item.index;
  }

  if (cost_up <= cost_down) {
    cost.cost = cost_up;
    cost.direction = UP;
    return cost;
  }
  cost.cost = cost_down;
  cost.direction = DOWN;
  return cost;
}
