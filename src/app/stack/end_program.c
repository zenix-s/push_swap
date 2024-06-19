/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:34:53 by serferna          #+#    #+#             */
/*   Updated: 2024/06/19 13:55:39 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	free_stack(t_stack *stack)
{
	if (stack->stack != NULL)
		free(stack->stack);
	free(stack);
}

void end_program(t_stacks *stacks)
{
  free_stack(stacks->stack_a);
  free_stack(stacks->stack_b);
  free(stacks);
}
