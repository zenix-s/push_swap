/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 21:24:18 by serferna          #+#    #+#             */
/*   Updated: 2024/07/02 16:29:24 by serferna         ###   ########.fr       */
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

static void	add_arg_fail(t_item **items, int i)
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
		if (!init_item(items, i, stack->items[i]->value,
				stack->items[i]->index))
			return (add_arg_fail(items, i), FALSE);
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

static void	chunk_error(char **chunk, int chunk_size, t_stack *stack)
{
	while (chunk_size >= 0)
	{
		free(chunk[chunk_size]);
		chunk_size--;
	}
	free(chunk);
	free_stack(stack);
}

t_bool	load_stack(t_stack *stack, int argc, char **argv)
{
	int		item;
	char	**chunk;
	int		size;

	while (--argc > 0)
	{
		if (is_invalid_arg(argv[argc]))
			return (free_stack(stack), FALSE);
		chunk = ft_split(argv[argc], ' ');
		size = 0;
		while (chunk[size])
			size++;
		if (size == 0)
			return (free_stack(stack), FALSE);
		while (--size >= 0)
		{
			if (!process_item(chunk[size], &item) || find_dup(stack, item))
				return (chunk_error(chunk, size, stack), FALSE);
			if (!add_arg(stack, item))
				return (chunk_error(chunk, size, stack), FALSE);
			free(chunk[size]);
		}
		free(chunk);
	}
	return (TRUE);
}
