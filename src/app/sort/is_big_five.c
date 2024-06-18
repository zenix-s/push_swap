/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_big_five.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 23:10:02 by serferna          #+#    #+#             */
/*   Updated: 2024/06/18 23:10:05 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_bool	is_big_five(t_sort_data *data, int value)
{
	if (value == data->max_1.value || value == data->max_2.value
		|| value == data->max_3.value || value == data->max_4.value
		|| value == data->max_5.value)
		return (TRUE);
	return (FALSE);
}
