/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:34:53 by serferna          #+#    #+#             */
/*   Updated: 2024/06/19 18:27:38 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	free_items(t_stack *stack)
{
	if (stack->allocated <= 0)
		return ;
	while (stack->allocated > 0)
	{
		free(stack->items[stack->allocated - 1]);
		stack->allocated--;
	}
	free(stack->items);
}

void	free_stack(t_stack *stack)
{
	free_items(stack);
	free(stack);
}

void	end_program(t_stacks *stacks)
{
	free_stack(stacks->stack_a);
	free_stack(stacks->stack_b);
	free(stacks);
}
