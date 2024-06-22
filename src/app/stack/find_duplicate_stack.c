/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_duplicate_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:53:21 by serferna          #+#    #+#             */
/*   Updated: 2024/06/19 15:02:57 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_bool	find_dup(const t_stack *stack, const int item)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->stack[i]->value == item)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
