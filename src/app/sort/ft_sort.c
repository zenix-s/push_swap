/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:30:42 by serferna          #+#    #+#             */
/*   Updated: 2024/06/18 15:29:11 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_sort_data *init_sort_data(t_stacks *stacks) {
  t_sort_data *data;
  int i;

  data = malloc(sizeof(t_sort_data));
  if (!data)
    error(stacks);
  t_item *sorted = malloc(sizeof(t_item) * stacks->stack_a->size);
  if (!sorted)
    error(stacks);
  i = 0;
  while (i < stacks->stack_a->size) {
    sorted[i].value = stacks->stack_a->stack[i].value;
    sorted[i].index = stacks->stack_a->stack[i].index;
    i++;
  }

  data->min = find_min(stacks->stack_a);
  // data->sorted = bubble_sort(stacks->stack_a->stack, stacks->stack_a->size);
  data->sorted = bubble_sort(sorted, stacks->stack_a->size);
  data->size = stacks->stack_a->size;
  data->max_1 = data->sorted[stacks->stack_a->size - 1];
  data->max_2 = data->sorted[stacks->stack_a->size - 2];
  data->max_3 = data->sorted[stacks->stack_a->size - 3];
  data->max_4 = data->sorted[stacks->stack_a->size - 4];
  data->max_5 = data->sorted[stacks->stack_a->size - 5];
  if (data->size % 2 == 0)
    data->pivot = data->sorted[(data->size - 2) / 2];
  else
    data->pivot = data->sorted[(data->size - 1) / 2];

  return data;
}

t_bool is_big_five(t_sort_data *data, int value) {
  if (value == data->max_1.value || value == data->max_2.value ||
      value == data->max_3.value || value == data->max_4.value ||
      value == data->max_5.value)
    return TRUE;
  return FALSE;
}

t_item find_target(t_stack *stack, int value) {
  t_item closest;
  int i;

  i = 0;
  closest.index = -1;
  closest.value = INT_MIN;
  while (i < stack->size) {
    if ((stack->stack[i].value > value &&
         (stack->stack[i].value < closest.value || closest.index == -1)))
      closest = stack->stack[i];
    i++;
  }
  return closest;
}

// move the item at the top of b to the target position in a
void push_to_target(t_stacks *stacks, t_item item) {
  t_item target;
  t_cost a_cost;
  t_cost b_cost;

  target = find_target(stacks->stack_a, item.value);
  a_cost = calc_cost(stacks->stack_a, target, TOP);
  b_cost = calc_cost(stacks->stack_b, item, TOP);
  if (a_cost.direction == UP && b_cost.direction == UP) {
    while (a_cost.cost && b_cost.cost) {
      rr(stacks);
      a_cost.cost--;
      b_cost.cost--;
    }
    while (a_cost.cost) {
      ra(stacks);
      a_cost.cost--;
    }
    while (b_cost.cost) {
      rb(stacks);
      b_cost.cost--;
    }
    pa(stacks);
  } else if (a_cost.direction == DOWN && b_cost.direction == DOWN) {

    while (a_cost.cost && b_cost.cost) {
      rrr(stacks);
      a_cost.cost--;
      b_cost.cost--;
    }
    while (a_cost.cost) {
      rra(stacks);
      a_cost.cost--;
    }
    while (b_cost.cost) {
      rrb(stacks);
      b_cost.cost--;
    }

    pa(stacks);
  } else if (a_cost.direction == UP && b_cost.direction == DOWN) {
    while (a_cost.cost) {
      ra(stacks);
      a_cost.cost--;
    }
    while (b_cost.cost) {
      rrb(stacks);
      b_cost.cost--;
    }
    pa(stacks);
  } else if (a_cost.direction == DOWN && b_cost.direction == UP) {
    while (a_cost.cost) {
      rra(stacks);
      a_cost.cost--;
    }
    while (b_cost.cost) {
      rb(stacks);
      b_cost.cost--;
    }
    pa(stacks);
  }
}

int calculate_operations(t_stacks *stacks, t_item item) {
  int total_cost;
  t_item closest;
  t_cost a_cost;
  t_cost b_cost;

  closest = find_target(stacks->stack_a, item.value);
  a_cost = calc_cost(stacks->stack_a, closest, TOP);
  b_cost = calc_cost(stacks->stack_b, item, TOP);
  if (a_cost.direction == UP && b_cost.direction == UP) {
    if (a_cost.cost > b_cost.cost) {
      total_cost = a_cost.cost;
    } else {
      total_cost = b_cost.cost;
    }
  } else if (a_cost.direction == DOWN && b_cost.direction == DOWN) {
    if (a_cost.cost > b_cost.cost) {
      total_cost = a_cost.cost;
    } else {
      total_cost = b_cost.cost;
    }
  } else {
    total_cost = a_cost.cost + b_cost.cost;
  }

  return total_cost;
}

int ft_sort(t_stacks *stacks) {
  t_sort_data *data;
  t_item item;
  int i;

  data = init_sort_data(stacks);
  if (is_sorted(stacks->stack_a))
    return 0;

  // ft_printf("pivot: %d -> %d\n", data->pivot.index, data->pivot.value);
  // ft_printf("min: %d -> %d\n", data->min.index, data->min.value);
  // ft_printf("max_1: %d -> %d\n", data->max_1.index, data->max_1.value);
  // ft_printf("max_2: %d -> %d\n", data->max_2.index, data->max_2.value);
  // ft_printf("max_3: %d -> %d\n", data->max_3.index, data->max_3.value);
  // ft_printf("max_4: %d -> %d\n", data->max_4.index, data->max_4.value);
  // ft_printf("max_5: %d -> %d\n", data->max_5.index, data->max_5.value);
  //
  // for(int i = 0; i < data->size; i++) {
  //   ft_printf("%d: %d\n", data->sorted[i].index, data->sorted[i].value);
  // }
  //
  // print_stack(stacks->stack_a);
  
  top_item(stacks, 'a', data->pivot);

  // Pre sort
  while (data->size) {
    if (is_big_five(data,
                    stacks->stack_a->stack[stacks->stack_a->size - 1].value))
      ra(stacks);
    else {
      pb(stacks);
      if (stacks->stack_b->stack[stacks->stack_b->size - 1].value >
          data->pivot.value)
        rb(stacks);
    }
    data->size--;
  }

  if (stacks->stack_a->size == 5)
    sort_five(stacks);

  // Operation return

  while (stacks->stack_b->size) {
    i = 0;
    item = stacks->stack_b->stack[stacks->stack_b->size - 1];
    while (i < stacks->stack_b->size) {
      if (calculate_operations(stacks, stacks->stack_b->stack[i]) <
          calculate_operations(stacks, item))
        item = stacks->stack_b->stack[i];
      i++;
    }
    push_to_target(stacks, item);
  }
  //
  top_item(stacks, 'a', find_min(stacks->stack_a));

  // print_stack(stacks->stack_a);
  // print_stack(stacks->stack_b);

  free(data);
  return 0;
}
