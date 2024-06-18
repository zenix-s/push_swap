/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 23:12:04 by serferna          #+#    #+#             */
/*   Updated: 2024/06/18 23:23:54 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_item	find_target(t_stack *stack, int value)
{
	t_item	closest;
	int		item_value;
	int		i;

	i = 0;
	closest.index = -1;
	closest.value = INT_MIN;
	while (i < stack->size)
	{
		item_value = stack->stack[i].value;
		if (item_value > value && (item_value < closest.value
				|| closest.index == -1))
			closest = stack->stack[i];
		i++;
	}
	return (closest);
}
