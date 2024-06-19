/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:35:33 by serferna          #+#    #+#             */
/*   Updated: 2024/06/19 14:56:02 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/**
 * Prints the stack.
 * @param stack Pointer to the stack.
 */
void print_stack(t_stack *stack) {
  int size;

  ft_printf("Stack %c\n", stack->id);
  ft_printf("Size: %d\n", stack->size);
  ft_printf("--------------------\n");
  size = stack->size;
  while (size - 1 >= 0) {
    ft_printf("%d: %d\n", stack->stack[size - 1]->index,
              stack->stack[size - 1]->value);
    size--;
  }
}
