/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:35:36 by serferna          #+#    #+#             */
/*   Updated: 2024/06/22 23:11:07 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(const int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc <= 1)
		return (ft_putstr_fd("Error\n", 2), 1);
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (stacks == NULL)
		return (1);
	init_stack('a', 0, &stacks->stack_a);
	load_stack(stacks, argc, argv);
	if (!init_stack('b', stacks->stack_a->size, &stacks->stack_b))
		return (end_program(stacks), 1);
	if (is_sorted(stacks->stack_a))
		return (end_program(stacks), (0));
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
