/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:35:18 by serferna          #+#    #+#             */
/*   Updated: 2024/06/17 23:37:29 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rra(const t_stacks *stacks)
{
	reverse_rotate_stack(stacks->stack_a);
	ft_putstr_fd("rra\n", 1);
}
