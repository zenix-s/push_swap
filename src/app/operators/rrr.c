/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:35:21 by serferna          #+#    #+#             */
/*   Updated: 2024/06/14 17:35:42 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// void	rrr(t_stack *stack_a, t_stack *stack_b)
void	rrr(const t_stacks* stacks)
{
	reverse_rotate_stack(stacks->stack_a);
	reverse_rotate_stack(stacks->stack_b);
	ft_putstr_fd("rrr\n", 1);
}
