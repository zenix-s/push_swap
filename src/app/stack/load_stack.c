#include "../../push_swap.h"

typedef struct s_result {
  int result;
  t_bool error;
} t_result;

t_result process_item(char *str) {
  int sign;
  t_result result;

  result.result = 0;
  result.error = 0;
  sign = 1;
  while (*str == ' ' || (*str >= 9 && *str <= 13))
    str++;
  if (*str == '-' || *str == '+') {
    if (*str == '-')
      sign = -1;
    str++;
  }
  while (*str >= '0' && *str <= '9') {
    result.result = (result.result * 10) + (*str - '0');
    str++;
  }
  if (*str != '\0')
    result.error = TRUE;
  result.result *= sign;
  return result;
}

void load_stack(t_stacks *stacks, int argc, char **argv) {
  t_result item;


  while (--argc > 0) {
    item = process_item(argv[argc]);
    if (item.error)
      error(stacks->stack_a, stacks->stack_b);
    push(stacks->stack_a, item.result);
  }
}
  // int sign;
  // size_t result;
  // size_t i;
  //
  // result = 0;
  // sign = 1;
  // i = 0;
  // while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
  //   i++;
  // if (str[i] == '-')
  //   sign = -1;
  // if (str[i] == '-' || str[i] == '+')
  //   i++;
  // while (ft_isdigit(str[i]) != 0) {
  //   result = (result * 10) + (str[i] - '0');
  //   i++;
  // }
  // return (result * sign);
