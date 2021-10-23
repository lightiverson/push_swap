#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Check welke libraries mogen!!!
# include <stdio.h>
# include "../libft/libft.h"
# include "./error_checks/error_checks.h"
# include "./setup_stacks/setup_stacks.h"
# include "./is/is.h"
# include "./utilities_algorithms/utilities_algorithms.h"
# include "./gets/gets.h"
# include "./algorithms/algorithms.h"
# include "./struct.h"

# define A   0
# define B   1

// push_swap.c
void	push_swap(t_stack *stack_a, t_stack *stack_b, int argc);

#endif /* PUSH_SWAP_H */