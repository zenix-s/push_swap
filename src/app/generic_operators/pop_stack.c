/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:34:55 by serferna          #+#    #+#             */
/*   Updated: 2024/06/19 16:35:27 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/**
 * Pops the top element of the stack.
 * @param stack Pointer to the stack.
 */
void pop_stack(t_stack *stack) {
  // t_item	*new_stack;
  // int		i;
  //
  if (stack->size == 0)
    return;
  // new_stack = (t_item *)malloc((stack->size - 1) * sizeof(t_item));
  // i = 0;
  // while (i < stack->size - 1)
  // {
  // 	new_stack[i] = stack->stack[i];
  // 	i++;
  // }
  // free(stack->stack);
  // stack->stack = new_stack;
  // stack->size--;

  stack->stack[stack->size - 1]->index = -1;
  stack->size--;
}
