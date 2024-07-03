/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:48:03 by serferna          #+#    #+#             */
/*   Updated: 2024/06/19 15:21:39 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

// Find the max item in the stack
t_item	*find_max(const t_stack *stack)
{
	t_item	*max;
	int		i;

	i = 0;
	max = stack->items[0];
	while (i < stack->size)
	{
		if (stack->items[i]->value > max->value)
			max = stack->items[i];
		i++;
	}
	return (max);
}
