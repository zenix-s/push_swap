/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_invalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:48:05 by serferna          #+#    #+#             */
/*   Updated: 2024/06/22 23:16:23 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static t_bool	is_invalid_char(const char c)
{
	if (!ft_isdigit(c) && c != '-' && c != '+' && c != ' ' && c != '\0')
		return (TRUE);
	return (FALSE);
}

t_bool	is_invalid_arg(const char *str)
{
	int	i;

	if (str[0] == '\0')
		return (FALSE);
	i = 0;
	while (str[i])
	{
		if (is_invalid_char(str[i]))
			return (TRUE);
		i++;
	}
	return (FALSE);
}
