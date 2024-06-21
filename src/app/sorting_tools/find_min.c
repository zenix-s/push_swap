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

t_item	*find_min(t_stack *stack)
{
	t_item	*min;
	int		i;

	i = 0;
	min = stack->stack[0];
	while (i < stack->size)
	{
		if (stack->stack[i]->value < min->value)
			min = stack->stack[i];
		i++;
	}
	return (min);
}
