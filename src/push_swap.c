/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:35:36 by serferna          #+#    #+#             */
/*   Updated: 2024/07/02 15:49:09 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	switch_sort(t_stacks *stacks)
{
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
}

int	main(const int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc <= 1)
		return (1);
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (stacks == NULL)
		return (print_error(), 1);
	if (!init_stack('a', 0, &stacks->stack_a))
		return (free(stacks), print_error(), 1);
	if (!load_stack(stacks->stack_a, argc, argv))
		return (free(stacks), print_error(), 1);
	if (is_sorted(stacks->stack_a))
		return (free_stack(stacks->stack_a), free(stacks), 0);
	if (!init_stack('b', stacks->stack_a->size, &stacks->stack_b))
		return (free_stack(stacks->stack_a), print_error(), free(stacks), 1);
	switch_sort(stacks);
	end_program(stacks);
	return (0);
}
