#ifndef IS_H
# define IS_H

# include <stdbool.h>
# include "../struct.h"
# include "../gets/gets.h"

bool	is_in_array(const t_stack *stack, int x);
int		back_inbound_down(const t_stack *stack_a, int index);
bool	is_ordered(const t_stack *stack);
bool	is_sorted(const t_stack *stack);

#endif /* IS_H */