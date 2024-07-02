/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:34:50 by serferna          #+#    #+#             */
/*   Updated: 2024/07/02 16:28:29 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	error(t_stacks *stacks)
{
	if (stacks != NULL)
		end_program(stacks);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
}
