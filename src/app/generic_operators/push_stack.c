/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:34:57 by serferna          #+#    #+#             */
/*   Updated: 2024/06/14 17:35:42 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/**
 * Pushes the top element of stack b to stack a.
 * @param stack Pointer to the stack.
 * @param element Element to push.
 */
void	push_stack(t_stack *stack, int element)
{
	t_item	*new_stack;
	int	i;

	new_stack = (t_item *)malloc((stack->size + 1) * sizeof(t_item));
	i = 0;
	while (i < stack->size)
	{
		new_stack[i] = stack->stack[i];
		i++;
	}
	new_stack[i].value = element;
  new_stack[i].index = i;
	free(stack->stack);
	stack->stack = new_stack;
	stack->size++;
}
