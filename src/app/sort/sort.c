/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 21:18:53 by serferna          #+#    #+#             */
/*   Updated: 2024/06/18 12:52:09 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"




// Find the closest item to the value in the stack max item if exists else min
t_item find_closest(t_stack *stack, int value) {
  t_item closest_min;
  t_item closest_max;
  int i;

  i = 0;
  closest_max.index = -1;
  closest_max.value = INT_MIN;
  closest_min.index = -1;
  closest_min.value = INT_MAX;
  while (i < stack->size) {
    if ((stack->stack[i].value > value &&
         (stack->stack[i].value < closest_max.value ||
          closest_max.index == -1)))
      closest_max = stack->stack[i];
    if ((stack->stack[i].value < value &&
         (stack->stack[i].value > closest_min.value ||
          closest_min.index == -1)))
      closest_min = stack->stack[i];
    i++;
  }
  if (closest_min.index == -1)
    return closest_max;
  return closest_min;
}




// Find the cost of moving the item to the top of the stack + the cost of moving
// + the cost of colocating the stack_b in position
t_total_cost cost_item(t_stacks *stacks, t_item item) {
  t_item closest;
  t_total_cost total_cost;
  t_cost a_cost;
  t_cost b_cost;

  closest = find_closest(stacks->stack_b, item.value);
  a_cost = calc_cost(stacks->stack_a, item, TOP);
  if (closest.value > item.value) {
    b_cost = calc_cost(stacks->stack_b, closest, BOTTOM);
  } else {
    b_cost = calc_cost(stacks->stack_b, closest, TOP);
  }
  total_cost.a_cost = a_cost;
  total_cost.b_cost = b_cost;
  total_cost.total_cost = a_cost.cost + b_cost.cost + 1;

  return total_cost;
}

int sort(t_stacks *stacks) {
  t_item item;
  int index;
  int operations;
  t_total_cost total_cost;

  pb(stacks);
  pb(stacks);
  pb(stacks);
  operations = 3;
  while (stacks->stack_a->size > 0) {
    index = 0;
    item = stacks->stack_a->stack[index];
    while (index < stacks->stack_a->size) {
      total_cost = cost_item(stacks, stacks->stack_a->stack[index]);
      if (total_cost.total_cost < cost_item(stacks, item).total_cost) {
        item = stacks->stack_a->stack[index];
      }
      index++;
    }
    while (total_cost.a_cost.cost > 0) {
      if (total_cost.a_cost.direction == UP) {
        ra(stacks);
      } else {
        rra(stacks);
      }
      operations++;
      total_cost.a_cost.cost--;
    }
    while (total_cost.b_cost.cost > 0) {
      if (total_cost.b_cost.direction == UP) {
        rb(stacks);
      } else {
        rrb(stacks);
      }
      operations++;
      total_cost.b_cost.cost--;
    }
    pb(stacks);
    operations++;
  }

  item = find_max(stacks->stack_b);
  top_item(stacks, 'b', item);
  while (stacks->stack_b->size > 0) {
    pa(stacks);
    operations++;
  }

  return operations;
}
