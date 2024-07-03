/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:34:57 by serferna          #+#    #+#             */
/*   Updated: 2024/06/19 20:28:45 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

/**
 * Pushes the top element of stack b to stack a.
 * @param stack Pointer to the stack.
 * @param element Element to push.
 */
void	push_stack(t_stack *stack, const int element)
{
	stack->items[stack->size]->index = stack->size;
	stack->items[stack->size]->value = element;
	stack->size++;
}
