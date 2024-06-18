/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sort_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 23:12:25 by serferna          #+#    #+#             */
/*   Updated: 2024/06/18 23:12:29 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_sort_data	*init_sort_data(t_stacks *stacks)
{
	t_sort_data	*data;

	data = malloc(sizeof(t_sort_data));
	if (!data)
		error(stacks);
	data->min = find_min(stacks->stack_a);
	data->sorted = bubble_sort_init_stack(stacks);
	data->size = stacks->stack_a->size;
	data->max_1 = data->sorted[stacks->stack_a->size - 1];
	data->max_2 = data->sorted[stacks->stack_a->size - 2];
	data->max_3 = data->sorted[stacks->stack_a->size - 3];
	data->max_4 = data->sorted[stacks->stack_a->size - 4];
	data->max_5 = data->sorted[stacks->stack_a->size - 5];
	if (data->size % 2 == 0)
		data->pivot = data->sorted[(data->size - 2) / 2];
	else
		data->pivot = data->sorted[(data->size - 1) / 2];
	return (data);
}
