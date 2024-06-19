/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:35:29 by serferna          #+#    #+#             */
/*   Updated: 2024/06/19 12:44:01 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack	*init_stack(char id, int stack_size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
  if (stack_size <= 0)
    stack->stack = NULL;
  else
    stack->stack = (t_item *)malloc(stack_size * sizeof(t_item));
	stack->id = id;
	return (stack);
}
