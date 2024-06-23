/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 21:24:18 by serferna          #+#    #+#             */
/*   Updated: 2024/06/23 22:48:03 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static t_bool	init_item(t_item **stack, const int i, const int value,
	const int index)
{
	stack[i] = (t_item *)malloc(sizeof(t_item));
	if (stack[i] == NULL)
		return (FALSE);
	stack[i]->value = value;
	stack[i]->index = index;
	return (TRUE);
}

static void add_arg_fail(t_item **items, int i)
{
	while (--i >= 0)
	{
		free(items[i]);
	}
	free(items);
}

static t_bool	add_arg(t_stack *stack, const int element)
{
	t_item	**items;
	int		i;

	items = (t_item **)malloc((stack->size + 1) * sizeof(t_item *));
	if (items == NULL)
		return (FALSE);
	i = 0;
	while (i < stack->size)
	{
		if (!init_item(items, i, stack->items[i]->value, stack->items[i]->index))
			return (add_arg_fail(items, i) ,FALSE);
		free(stack->items[i]);
		i++;
	}
	if (!init_item(items, i, element, i))
		return (add_arg_fail(items, i), FALSE);
	free(stack->items);
	stack->items = items;
	stack->size++;
	stack->allocated++;
	return (TRUE);
}

static void	chunk_error(char **chunk, int chunk_size, t_stacks *stacks)
{
	while (chunk_size >= 0)
	{
		free(chunk[chunk_size]);
		chunk_size--;
	}
	free(chunk);
	free_stack(stacks->stack_a);
	free(stacks);
	exit(1);
}

void	load_stack(t_stacks *stacks, int argc, char **argv)
{
	int		item;
	char	**chunk;
	int		chunk_size;

	while (--argc > 0)
	{
		if (is_invalid_arg(argv[argc]))
			error(stacks);
		chunk = ft_split(argv[argc], ' ');
		chunk_size = 0;
		while (chunk[chunk_size])
			chunk_size++;
		if (chunk_size == 0)
			return (free_stack(stacks->stack_a), free(stacks));
		while (--chunk_size >= 0)
		{
			if (!process_item(chunk[chunk_size], &item))
				return (chunk_error(chunk, chunk_size, stacks));
			if (find_dup(stacks->stack_a, item))
				return (chunk_error(chunk, chunk_size, stacks));
			if (!add_arg(stacks->stack_a, item))
				return (chunk_error(chunk, chunk_size, stacks));
			free(chunk[chunk_size]);
		}
		free(chunk);
	}
}
