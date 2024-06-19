/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:35:04 by serferna          #+#    #+#             */
/*   Updated: 2024/06/19 14:58:14 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/**
 * Swaps the top two elements of the stack.
 * @param stack Pointer to the stack.
 */
void swap_stack(t_stack *stack) {
  int tmp;

  if (stack->size < 2)
    return;
  tmp = stack->stack[stack->size - 1]->value;
  stack->stack[stack->size - 1]->value = stack->stack[stack->size - 2]->value;
  stack->stack[stack->size - 2]->value = tmp;
}
