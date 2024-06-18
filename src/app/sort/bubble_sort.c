/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:22:18 by serferna          #+#    #+#             */
/*   Updated: 2024/06/18 15:29:13 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void swap(int *a, int *b) {
  int tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

// stack is an array of t_item {int value}
t_item *bubble_sort(t_item *stack, int size) {
  int i;
  int j;
  int n;

  n = size;
  i = 0;
  while (i < n - 1) {
    j = 0;
    while (j < n - i - 1) {
      if (stack[j].value > stack[j + 1].value)
      {
        swap(&stack[j].value, &stack[j + 1].value);
        swap(&stack[j].index, &stack[j + 1].index);
      }
      j++;
    }
    i++;
  }
  return stack;
}
