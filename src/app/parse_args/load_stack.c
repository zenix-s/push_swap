/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:35:31 by serferna          #+#    #+#             */
/*   Updated: 2024/06/19 20:33:20 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	add_arg(t_stack *stack, const int element)
{
	t_item	**new_stack;
	int		i;

	new_stack = (t_item **)malloc((stack->size + 1) * sizeof(t_item *));
	i = 0;
	while (i < stack->size)
	{
		new_stack[i] = (t_item *)malloc(sizeof(t_item));
		new_stack[i]->value = stack->stack[i]->value;
		new_stack[i]->index = stack->stack[i]->index;
		free(stack->stack[i]);
		i++;
	}
	new_stack[i] = (t_item *)malloc(sizeof(t_item));
	new_stack[i]->value = element;
	new_stack[i]->index = i;
	free(stack->stack);
	stack->stack = new_stack;
	stack->size++;
	stack->allocated++;
}

void	load_stack(t_stacks *stacks, int argc, char **argv)
{
	int		item;
	char	**chunk;
	int		chunk_size;

	if (argc < 2)
		error(stacks);
	while (--argc > 0)
	{
		if (is_invalid_arg(argv[argc]))
			error(stacks);
		chunk = ft_split(argv[argc], ' ');
		chunk_size = 0;
		while (chunk[chunk_size])
			chunk_size++;
		while (--chunk_size >= 0)
		{
			if (!process_item(chunk[chunk_size], &item))
				return (free(chunk), error(stacks));
			if (find_dup(stacks->stack_a, item))
				return (free(chunk), error(stacks));
			add_arg(stacks->stack_a, item);
			free(chunk[chunk_size]);
		}
		free(chunk);
	}
}
