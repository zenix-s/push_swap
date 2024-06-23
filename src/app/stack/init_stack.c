/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 21:24:18 by serferna          #+#    #+#             */
/*   Updated: 2024/06/22 22:55:14 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:35:29 by serferna          #+#    #+#             */
/*   Updated: 2024/06/19 18:29:09 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	init_fail(t_stack **stack, int stack_size)
{
	while (stack_size <= (*stack)->allocated)
	{
		free((*stack)->items[stack_size - 1]);
		stack_size++;
	}
	free((*stack)->items);
	free(*stack);
	*stack = NULL;
}

t_bool	init_stack(const char id, int size, t_stack **stack)
{
	t_item	**items;

	*stack = (t_stack *)malloc(sizeof(t_stack));
	(*stack)->size = 0;
	(*stack)->allocated = 0;
	(*stack)->id = id;
	if (size <= 0)
		(*stack)->items = NULL;
	else
	{
		items = (t_item **)malloc(size * sizeof(t_item *));
		(*stack)->allocated = size;
		while (size > 0)
		{
			items[size - 1] = (t_item *)malloc(sizeof(t_item));
			if (items[size - 1] == NULL)
				return ((*stack)->items = items, init_fail(stack, size), FALSE);
			items[size - 1]->index = -1;
			size--;
		}
		(*stack)->items = items;
	}
	return (TRUE);
}
