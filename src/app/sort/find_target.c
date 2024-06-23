/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 23:12:04 by serferna          #+#    #+#             */
/*   Updated: 2024/06/19 20:33:48 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_item	*find_target(const t_stack *stack, const int value)
{
	t_item	*closest;
	int		item_value;
	int		i;

	i = 0;
	while (stack->items[i]->value < value)
		i++;
	closest = stack->items[i];
	while (i < stack->size)
	{
		item_value = stack->items[i]->value;
		if (item_value > value && item_value < closest->value)
			closest = stack->items[i];
		i++;
	}
	return (closest);
}
