/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:48:03 by serferna          #+#    #+#             */
/*   Updated: 2024/06/17 23:23:54 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
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
