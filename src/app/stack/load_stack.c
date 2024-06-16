/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:35:31 by serferna          #+#    #+#             */
/*   Updated: 2024/06/14 17:53:36 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_bool is_invalid_arg(char *str) {
  int i;

  i = 0;
  while (str[i]) {
    if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+' && str[i] != ' ')
      return (TRUE);
    i++;
  }
  return (FALSE);
}

t_bool process_item(char *str, int *item) {
  int sign;
  long long value;

  value = 0;
  sign = 1;
  if (*str == '-' || *str == '+') {
    if (ft_strlen(str) == 1)
      return (FALSE);
    if (*str == '-')
      sign = -1;
    str++;
  }
  while (*str >= '0' && *str <= '9') {
    value = (value * 10) + (*str - '0');
    if (sign == 1 && value > INT_MAX)
      return (FALSE);
    if (sign == -1 && value > (long long)INT_MAX + 1)
      return (FALSE);
    str++;
  }
  if (*str != '\0')
    return (FALSE);
  value *= sign;
  *item = (int)value;
  return (TRUE);
}

void load_stack(t_stacks *stacks, int argc, char **argv) {
  int item;
  char **chunk;
  int chunk_size;

  (void)item;
  if (argc < 2)
    error(stacks);
  while (--argc > 0) {
    if (is_invalid_arg(argv[argc]))
      error(stacks);
    chunk = ft_split(argv[argc], ' ');
    chunk_size = 0;
    while (chunk[chunk_size])
      chunk_size++;
    while (--chunk_size >= 0) {
      if (!process_item(chunk[chunk_size], &item))
        error(stacks);
      if (find_dup(stacks->stack_a, item))
        error(stacks);
      push_stack(stacks->stack_a, item);
    }
  }
}
