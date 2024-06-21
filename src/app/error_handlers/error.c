/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:34:50 by serferna          #+#    #+#             */
/*   Updated: 2024/06/19 18:26:42 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	error(t_stacks *stacks)
{
	if (stacks != NULL)
		end_program(stacks);
	write(2, "Error\n", 6);
	exit(1);
}
