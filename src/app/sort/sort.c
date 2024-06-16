/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 21:18:53 by serferna          #+#    #+#             */
/*   Updated: 2024/06/17 01:34:08 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

typedef enum e_direction { UP, DOWN } t_direction;

typedef struct s_cost {
  int cost;
  t_direction direction;
} t_cost;

typedef struct s_total_cost {
  t_cost a_cost;
  t_cost b_cost;
  int total_cost;
} t_total_cost;

// Cost to move item to top of the stack and the direction to do it
t_cost cost_to_top(t_stack *stack, t_item item) {
  t_cost cost;
  int cost_up;
  int cost_down;

  cost_up = (stack->size - 1) - item.index;
  cost_down = item.index + 1;
  if (cost_up <= cost_down) {
    cost.cost = cost_up;
    cost.direction = UP;
    return cost;
  }
  cost.cost = cost_down;
  cost.direction = DOWN;
  return cost;
}

// Cost to move item to bottom of the stack and the direction
t_cost cost_to_bottom(t_stack *stack, t_item item) {
  t_cost cost;
  int cost_up;
  int cost_down;

  cost_up = (stack->size - 1) - item.index + 1;
  cost_down = item.index;
  if (cost_up <= cost_down) {
    cost.cost = cost_up;
    cost.direction = UP;
    return cost;
  }
  cost.cost = cost_down;
  cost.direction = DOWN;
  return cost;
}

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
    if ((stack->stack[i].value < value &&
         (stack->stack[i].value > closest_max.value ||
          closest_max.index == -1)))
      closest_max = stack->stack[i];
    if ((stack->stack[i].value > value &&
         (stack->stack[i].value < closest_min.value ||
          closest_min.index == -1)))
      closest_min = stack->stack[i];
    i++;
  }
  if (closest_min.index == -1)
    return closest_max;
  return closest_min;
}

// Find the max item in the stack
t_item find_max(t_stack *stack) {
  t_item max;
  int i;

  i = 0;
  max.index = -1;
  max.value = INT_MIN;
  while (i < stack->size) {
    if (stack->stack[i].value > max.value) {
      max = stack->stack[i];
    }
    i++;
  }
  return max;
}

void top_item(t_stacks *stacks, char stack_id, t_item item) {
  int top_index;

  if (stack_id == 'a') {
    top_index = stacks->stack_a->size - 1;
    while (stacks->stack_a->stack[top_index].value != item.value) {
      ra(stacks);
    }
  } else {
    top_index = stacks->stack_b->size - 1;
    while (stacks->stack_b->stack[top_index].value != item.value) {
      rb(stacks);
    }
  }
}

void bottom_item(t_stacks *stacks, char stack_id, t_item item) {
  int bottom_index;

  if (stack_id == 'a') {
    bottom_index = 0;
    while (stacks->stack_a->stack[bottom_index].value != item.value) {
      ra(stacks);
    }
  } else {
    bottom_index = 0;
    while (stacks->stack_b->stack[bottom_index].value != item.value) {
      rb(stacks);
    }
  }
}

// Find the cost of moving the item to the top of the stack + the cost of moving
// + the cost of colocating the stack_b in position
t_total_cost cost_item(t_stacks *stacks, t_item item) {
  t_item closest;
  t_total_cost total_cost;
  t_cost a_cost;
  t_cost b_cost;

  closest = find_closest(stacks->stack_b, item.value);
  a_cost = cost_to_top(stacks->stack_a, item);
  if (closest.value > item.value) {
    b_cost = cost_to_top(stacks->stack_b, closest);
  } else {
    b_cost = cost_to_bottom(stacks->stack_b, closest);
  }
  total_cost.a_cost = a_cost;
  total_cost.b_cost = b_cost;
  total_cost.total_cost = a_cost.cost + b_cost.cost + 1;

  return total_cost;
}

int ft_sort(t_stacks *stacks) {
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
  bottom_item(stacks, 'b', item);
  while (stacks->stack_b->size > 0) {
    rrb(stacks);
    pa(stacks);
    operations++;
  }

  return operations;
}
