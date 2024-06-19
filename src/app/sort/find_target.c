/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 23:12:04 by serferna          #+#    #+#             */
/*   Updated: 2024/06/19 17:36:21 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_item *find_target(t_stack *stack, int value) {
  t_item *closest;
  int item_value;
  int i;

  i = 0;
  while (stack->stack[i]->value < value)
    i++;
  closest = stack->stack[i];
  while (i < stack->size) {
    item_value = stack->stack[i]->value;
    // ft_printf("%d > %d && %d < %d\n", item_value, value, item_value,
    //           closest->value);
    if (item_value > value && item_value < closest->value)
      closest = stack->stack[i];
    i++;
  }
  // ft_printf("\n\n");
  return (closest);
}
