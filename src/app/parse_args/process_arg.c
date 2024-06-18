/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:48:51 by serferna          #+#    #+#             */
/*   Updated: 2024/06/18 21:52:13 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_bool	check_sign(char *str, int *sign)
{
	if (*str == '-' || *str == '+')
	{
		if (ft_strlen(str) == 1)
			return (FALSE);
		if (*str == '-')
			*sign = -1;
		str++;
	}
	return (TRUE);
}

t_bool	process_item(char *str, int *item)
{
	int			sign;
	long long	value;

	value = 0;
	sign = 1;
	if (!check_sign(str, &sign))
		return (FALSE);
	while (*str >= '0' && *str <= '9')
	{
		value = (value * 10) + (*str - '0');
		if ((sign == 1 && value > INT_MAX) || (sign == -1
				&& value > (long long)INT_MAX + 1))
			return (FALSE);
		str++;
	}
	if (*str != '\0')
		return (FALSE);
	value *= sign;
	*item = (int)value;
	return (TRUE);
}
