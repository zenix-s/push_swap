/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 00:03:53 by serferna          #+#    #+#             */
/*   Updated: 2024/06/18 00:03:58 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void sort_five(t_stacks *stacks) {
  t_item min;

  if (is_sorted(stacks->stack_a))
    return;

  min = find_min(stacks->stack_a);
  top_item(stacks, 'a', min);
  if (is_sorted(stacks->stack_a))
    return;
  pb(stacks);
  sort_four(stacks);
  pa(stacks);
}
