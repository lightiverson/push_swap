#ifndef ALGORITHMS_H
# define ALGORITHMS_H

# include "../struct.h"
# include "../gets/gets.h"
# include "../is/is.h"
# include "../operations/operations.h"
# include "../utilities_algorithms/utilities_algorithms.h"
# include <stdlib.h>
# include <stdio.h>
# include "../setup_stacks/setup_stacks.h"

void	sort_five(t_stack *stack_a, t_stack *stack_b);
void	sort_three(t_stack *stack_a);

void copy_stack_a_b(t_stack *stack_a, t_stack *stack_b);
void bubble_sort_descending(t_stack *stack_a, t_stack *stack_b);
void convert_stack_a_to_positive_ints(t_stack *stack_a, t_stack *stack_b);
void radix_sort(t_stack *stack_a, t_stack *stack_b);

#endif /* ALGORITHMS_H */