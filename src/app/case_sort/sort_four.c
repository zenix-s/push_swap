/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:10:42 by serferna          #+#    #+#             */
/*   Updated: 2024/06/19 17:11:52 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_four(t_stacks *stacks)
{
	t_item	*min;

	if (is_sorted(stacks->stack_a))
		return ;
	min = find_min(stacks->stack_a);
	top_item(stacks, 'a', min);
	if (is_sorted(stacks->stack_a))
		return ;
	pb(stacks);
	sort_three(stacks);
	pa(stacks);
}
