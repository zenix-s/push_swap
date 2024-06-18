/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:35:31 by serferna          #+#    #+#             */
/*   Updated: 2024/06/18 21:49:15 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

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
				error(stacks);
			if (find_dup(stacks->stack_a, item))
				error(stacks);
			push_stack(stacks->stack_a, item);
		}
	}
}
