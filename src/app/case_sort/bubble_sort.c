/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:22:18 by serferna          #+#    #+#             */
/*   Updated: 2024/06/18 23:06:35 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_item	*bubble_sort_init_stack(t_stacks *stacks)
{
	t_item	*sorted;
	int		i;

	sorted = malloc(sizeof(t_item) * stacks->stack_a->size);
	if (!sorted)
		error(stacks);
	i = 0;
	while (i < stacks->stack_a->size)
	{
		sorted[i].value = stacks->stack_a->stack[i].value;
		sorted[i].index = stacks->stack_a->stack[i].index;
		i++;
	}
	return (bubble_sort(sorted, stacks->stack_a->size));
}

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

t_item	*bubble_sort(t_item *stack, int size)
{
	int	i;
	int	j;
	int	n;

	n = size;
	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (stack[j].value > stack[j + 1].value)
			{
				swap(&stack[j].value, &stack[j + 1].value);
				swap(&stack[j].index, &stack[j + 1].index);
			}
			j++;
		}
		i++;
	}
	return (stack);
}
