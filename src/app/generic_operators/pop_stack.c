/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:34:55 by serferna          #+#    #+#             */
/*   Updated: 2024/06/19 20:28:40 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/**
 * Pops the top element of the stack.
 * @param stack Pointer to the stack.
 */
void	pop_stack(t_stack *stack)
{
	if (stack->size == 0)
		return ;
	stack->items[stack->size - 1]->index = -1;
	stack->size--;
}
