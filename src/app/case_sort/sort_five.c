/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 00:03:53 by serferna          #+#    #+#             */
/*   Updated: 2024/06/19 16:52:38 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_five(const t_stacks *stacks)
{
	t_item	*min;

	min = find_min(stacks->stack_a);
	top_item(stacks, 'a', min);
	if (is_sorted(stacks->stack_a))
		return ;
	pb(stacks);
	sort_four(stacks);
	pa(stacks);
}
