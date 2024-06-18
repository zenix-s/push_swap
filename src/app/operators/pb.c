/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:35:11 by serferna          #+#    #+#             */
/*   Updated: 2024/06/14 17:35:42 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	pb(t_stacks *stacks)
{
	if (stacks->stack_a->size == 0)
		return ;
	push_stack(stacks->stack_b, stacks->stack_a->stack[stacks->stack_a->size
		- 1].value);
	pop_stack(stacks->stack_a);
	ft_printf("pb\n");
}
