/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:22:18 by serferna          #+#    #+#             */
/*   Updated: 2024/06/19 14:56:43 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	*bubble_sort_init_stack(t_stacks *stacks)
{
	int	sorted;
	int	i;

	sorted = malloc(sizeof(int) * stacks->stack_a->size);
	if (sorted == NULL)
		return (error(stacks), NULL);
	i = 0;
	while (i < stacks->stack_a->size)
	{
		sorted[i] = stacks->stack_a->items[i]->value;
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

int	*bubble_sort(int *stack, const int size)
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
			if (stack[j] > stack[j + 1])
				swap(&stack[j], &stack[j + 1]);
			j++;
		}
		i++;
	}
	return (stack);
}
