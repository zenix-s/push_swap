/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:35:36 by serferna          #+#    #+#             */
/*   Updated: 2024/06/19 13:55:59 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	stacks->stack_a = init_stack('a', 0);
	load_stack(stacks, argc, argv);
	if (is_sorted(stacks->stack_a))
	{
    end_program(stacks);
		return (0);
	}
	stacks->stack_b = init_stack('b', 0);
	if (stacks->stack_a->size == 2)
		sort_two(stacks);
	else if (stacks->stack_a->size == 3)
		sort_three(stacks);
	else if (stacks->stack_a->size == 4)
		sort_four(stacks);
	else if (stacks->stack_a->size == 5)
		sort_five(stacks);
	else
		ft_sort(stacks);
  end_program(stacks);
	return (0);
}
