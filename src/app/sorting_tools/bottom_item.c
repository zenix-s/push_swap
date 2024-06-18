/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bottom_item.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:24:11 by serferna          #+#    #+#             */
/*   Updated: 2024/06/18 12:51:58 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void bottom_item(t_stacks *stacks, char stack_id, t_item item) {
  int cost_up;
  int cost_down;

  if (stack_id == 'a') {
    cost_up = (stacks->stack_a->size - 1) - item.index + 1;
    cost_down = item.index;
  } else {
    cost_up = (stacks->stack_b->size - 1) - item.index + 1;
    cost_down = item.index;
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
