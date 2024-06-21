/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:35:11 by serferna          #+#    #+#             */
/*   Updated: 2024/06/19 16:51:47 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	pb(t_stacks *stacks)
{
	int	a_value;

	if (stacks->stack_a->size == 0)
		return ;
	a_value = stacks->stack_a->stack[stacks->stack_a->size - 1]->value;
	push_stack(stacks->stack_b, a_value);
	pop_stack(stacks->stack_a);
	ft_printf("pb\n");
}
