/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:11:20 by serferna          #+#    #+#             */
/*   Updated: 2024/06/19 15:17:24 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_item	*find_min(const t_stack *stack)
{
	t_item	*min;
	int		i;

	i = 0;
	min = stack->items[0];
	while (i < stack->size)
	{
		if (stack->items[i]->value < min->value)
			min = stack->items[i];
		i++;
	}
	return (min);
}
