#ifndef IS_H
# define IS_H

# include <stdbool.h>
# include "../struct.h"
# include "../gets/gets.h"

bool	is_ordered(const t_stack *stack);
bool	is_sorted(const t_stack *stack);

#endif /* IS_H */