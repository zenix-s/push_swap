/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sort_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 23:12:25 by serferna          #+#    #+#             */
/*   Updated: 2024/06/19 20:01:27 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_item	select_pivot(t_item *sorted, int size)
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
	if (!data)
		error(stacks);
	sorted = bubble_sort_init_stack(stacks);
	data->size = stacks->stack_a->size;
	data->min = sorted[0];
	data->max_1 = sorted[stacks->stack_a->size - 1];
	data->max_2 = sorted[stacks->stack_a->size - 2];
	data->max_3 = sorted[stacks->stack_a->size - 3];
	data->max_4 = sorted[stacks->stack_a->size - 4];
	data->max_5 = sorted[stacks->stack_a->size - 5];
	data->pivot = select_pivot(sorted, data->size);
  // ft_printf("pivot: %d\n", data->pivot);
  // ft_printf("max_1: %d\n", data->max_1);
  // ft_printf("max_2: %d\n", data->max_2);
  // ft_printf("max_3: %d\n", data->max_3);
  // ft_printf("max_4: %d\n", data->max_4);
  // ft_printf("max_5: %d\n", data->max_5);
  // ft_printf("min: %d\n", data->min);
	free(sorted);
	return (data);
}
