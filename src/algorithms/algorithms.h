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

// bubble_sort.c
int		back_inbound_top(const t_stack *stack_a, int index);
void	bubble_sort_norm_helper(t_stack *stack_a,
			t_stack *stack_b, int top_dup);
void	bubble_sort_norm(t_stack *stack_a, t_stack *stack_b);

// radix_sort.c
void	copy_stack_a_b(t_stack *stack_a, t_stack *stack_b);
void	convert_stack_a_to_positive_ints(t_stack *stack_a, t_stack *stack_b);
int		get_place_most_significant_set_bit(int x);
void	radix_sort_twee(t_stack *stack_a, t_stack *stack_b);

// sort_large.c
void	sort_large(t_stack *stack_a, t_stack *stack_b);

#endif /* ALGORITHMS_H */