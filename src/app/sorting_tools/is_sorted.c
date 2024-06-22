/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:35:18 by serferna          #+#    #+#             */
/*   Updated: 2024/06/19 15:02:41 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/**
 * Check if stack is sorted
 */
t_bool	is_sorted(const t_stack *stack)
{
	int	index;

	index = 0;
	while (index < stack->size - 1)
	{
		if (stack->stack[index]->value < stack->stack[index + 1]->value)
			return (FALSE);
		index++;
	}
	return (TRUE);
}
