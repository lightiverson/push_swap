#ifndef SETUP_STACKS_H
#define SETUP_STACKS_H

void print_stack(const t_stack *stack);
void free_stacks(t_stack *stack_a, t_stack *stack_b);
void populate_stack(int argc, char *argv[], t_stack *stack);
void initialize_stack(t_stack *stack, int len, char stack_name);

#endif /* SETUP_STACKS_H */