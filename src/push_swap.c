/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:35:36 by serferna          #+#    #+#             */
/*   Updated: 2024/06/18 12:57:44 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	stacks->stack_a = init_stack('a');
	stacks->stack_b = init_stack('b');
	load_stack(stacks, argc, argv);
  // INICIO PROGRAMA
  
  // print_stack(stacks->stack_a);
  // operations = ft_sort(stacks);
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
  // ft_printf("OPERATIONS: %d\n", operations);
  // print_stack(stacks->stack_a);
  // print_stack(stacks->stack_b);

  // FIN PROGRAMA
	free_stack(stacks->stack_a);
	free_stack(stacks->stack_b);
	free(stacks);
	return (0);
}
