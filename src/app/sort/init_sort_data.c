/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sort_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 23:12:25 by serferna          #+#    #+#             */
/*   Updated: 2024/06/19 20:29:25 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_item	select_pivot(const t_item *sorted, const int size)
{
	t_item	pivot;

	if (size % 2 == 0)
		pivot = sorted[size / 2];
	else
		pivot = sorted[(size - 1) / 2];
	return (pivot);
}

t_sort_data	*init_sort_data(t_stacks *stacks)
{
	t_sort_data	*data;
	t_item		*sorted;

	data = malloc(sizeof(t_sort_data));
	if (data == NULL)
		return error(stacks), NULL;
	sorted = bubble_sort_init_stack(stacks);
	data->size = stacks->stack_a->size;
	data->min = sorted[0];
	data->max_1 = sorted[stacks->stack_a->size - 1];
	data->max_2 = sorted[stacks->stack_a->size - 2];
	data->max_3 = sorted[stacks->stack_a->size - 3];
	data->max_4 = sorted[stacks->stack_a->size - 4];
	data->max_5 = sorted[stacks->stack_a->size - 5];
	data->pivot = select_pivot(sorted, data->size);
	free(sorted);
	return (data);
}
