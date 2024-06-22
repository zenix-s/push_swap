/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:35:03 by serferna          #+#    #+#             */
/*   Updated: 2024/06/19 14:57:54 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/**
 * Rotates the stack. The top element becomes the bottom element.
 * @param stack Pointer to the stack.
 */
void	rotate_stack(const t_stack* stack)
{
	int	tmp;
	int	i;

	if (stack->size < 2)
		return ;
	tmp = stack->stack[stack->size - 1]->value;
	i = stack->size - 1;
	while (i > 0)
	{
		stack->stack[i]->value = stack->stack[i - 1]->value;
		i--;
	}
	stack->stack[0]->value = tmp;
}
