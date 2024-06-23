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

void	free_stack(t_stack *stack)
{
	while (stack->allocated > 0)
	{
		free(stack->items[stack->allocated - 1]);
		stack->allocated--;
	}
	free(stack->items);
	free(stack);
}

// Función para finalizar el programa y liberar toda la memoria
void	end_program(t_stacks *stacks)
{
	free_stack(stacks->stack_a);
	free_stack(stacks->stack_b);
	free(stacks);
}
