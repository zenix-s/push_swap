/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:30:42 by serferna          #+#    #+#             */
/*   Updated: 2024/06/19 20:04:53 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void pre_sort(t_stacks *stacks, t_sort_data *data) {
  t_item *item;

  while (data->size) {
    item = stacks->stack_a->stack[stacks->stack_a->size - 1];
    if (is_big_five(data, item->value)) {
      // ft_printf("is big five: %d\n", item->value);
      // ft_printf("pivot: %d\n", data->pivot);
      // ft_printf("max_1: %d\n", data->max_1);
      // ft_printf("max_2: %d\n", data->max_2);
      // ft_printf("max_3: %d\n", data->max_3);
      // ft_printf("max_4: %d\n", data->max_4);
      // ft_printf("max_5: %d\n", data->max_5);
      // ft_printf("min: %d\n", data->min);
      ra(stacks);
    } else {
      pb(stacks);
      item = stacks->stack_b->stack[stacks->stack_b->size - 1];
      if (item->value > data->pivot.value && stacks->stack_b->size > 2)
        rb(stacks);
    }
    data->size--;
  }
}

static void operation_return(t_stacks *stacks) {
  int i;
  t_item *item;

  while (stacks->stack_b->size) {
    i = 0;
    item = stacks->stack_b->stack[0];
    while (i < stacks->stack_b->size) {
      if (calculate_operations(stacks, stacks->stack_b->stack[i]) <
          calculate_operations(stacks, item))
        item = stacks->stack_b->stack[i];
      i++;
    }
    push_to_target(stacks, item);
  }
}

int ft_sort(t_stacks *stacks) {
  t_sort_data *data;

  data = init_sort_data(stacks);
  pre_sort(stacks, data);
  if (stacks->stack_a->size == 5)
    sort_five(stacks);
  if (stacks->stack_a->size == 4)
    sort_four(stacks);
  operation_return(stacks);
  top_item(stacks, 'a', find_min(stacks->stack_a));
  free(data);
  return (0);
}
