/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_item.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:54:28 by serferna          #+#    #+#             */
/*   Updated: 2024/06/18 12:50:23 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/**
 * Moves the item to the top of the stack
 *
 */
void top_item(t_stacks *stacks, char stack_id, t_item item) {
  int cost_up;
  int cost_down;

  if (stack_id == 'a') {
    cost_up = (stacks->stack_a->size - 1) - item.index;
    cost_down = item.index + 1;
  } else {
    cost_up = (stacks->stack_b->size - 1) - item.index;
    cost_down = item.index + 1;
  }

  if (cost_up <= cost_down) {
    while (cost_up > 0) {
      if (stack_id == 'a')
        ra(stacks);
      else
        rb(stacks);
      cost_up--;
    }
  } else {
    while (cost_down > 0) {
      if (stack_id == 'a')
        rra(stacks);
      else
        rrb(stacks);
      cost_down--;
    }
  }
}
