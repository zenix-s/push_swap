/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:35:29 by serferna          #+#    #+#             */
/*   Updated: 2024/06/19 18:29:09 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack *init_stack(char id, int stack_size) {
  t_stack *stack;
  t_item **items;

  stack = (t_stack *)malloc(sizeof(t_stack));
  stack->size = 0;
  stack->allocated = 0;
  if (stack_size <= 0) {
    stack->stack = NULL;
  } else {
    items = (t_item **)malloc(stack_size * sizeof(t_item *));
    stack->allocated = stack_size;
    while (stack_size > 0) {
      items[stack_size - 1] = (t_item *)malloc(sizeof(t_item));
      items[stack_size - 1]->index = -1;
      stack_size--;
    }
    stack->stack = items;
  }
  stack->id = id;
  return (stack);
}
