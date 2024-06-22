/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:35:00 by serferna          #+#    #+#             */
/*   Updated: 2024/06/19 14:57:37 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/**
 * Reverses the stack. The last element becomes the first, the second to last
 * @param stack Pointer to the stack.
 */
void	reverse_rotate_stack(const t_stack* stack)
{
	int	tmp;
	int	i;

	if (stack->size < 2)
		return ;
	tmp = stack->stack[0]->value;
	i = 0;
	while (i < stack->size - 1)
	{
		stack->stack[i]->value = stack->stack[i + 1]->value;
		i++;
	}
	stack->stack[stack->size - 1]->value = tmp;
}
