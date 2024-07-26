/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:48:51 by serferna          #+#    #+#             */
/*   Updated: 2024/06/22 20:00:20 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static t_bool	process_sign(const char *str, int *sign, int *i)
{
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (ft_strlen(str) == 1)
			return (FALSE);
		if (str[*i] == '-')
			*sign = -1;
		*i = *i + 1;
	}
	return (TRUE);
}

static t_bool	is_overflow(int sign, long long value)
{
	if ((sign == 1 && value > INT_MAX))
		return (TRUE);
	else if (sign == -1 && value > (long long)INT_MAX + 1)
		return (TRUE);
	return (FALSE);
}

t_bool	process_item(const char *str, int *item)
{
	int			sign;
	long long	value;
	int			i;

	i = 0;
	value = 0;
	sign = 1;
	if (!process_sign(str, &sign, &i))
		return (FALSE);
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = (value * 10) + (str[i] - '0');
		if (is_overflow(sign, value))
			return (FALSE);
		i++;
	}
	if (str[i] != '\0')
		return (FALSE);
	value *= sign;
	*item = (int)value;
	return (TRUE);
}
