/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:35:18 by serferna          #+#    #+#             */
/*   Updated: 2024/06/17 23:24:09 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/**
 * Ceck if stack is sorted
 * 0 1 2 3 4 5 6 7 8 9
 */
t_bool is_sorted(t_stack *stack) {
  int index;

  index = 0;
  while (index < stack->size - 1) {
    if (stack->stack[index].value < stack->stack[index + 1].value)
      return (FALSE);
    index++;
  }
  return (TRUE);
}
