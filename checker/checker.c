#include "./checker.h"

void execute_operations(t_stack *stack_a, t_stack *stack_b, char *operation)
{
    if (!strcmp(operation, "sa"))
        swap_a_or_b(stack_a);
    else if (!strcmp(operation, "sb"))
        swap_a_or_b(stack_b);
    else if (!strcmp(operation, "ss"))
        swap_ab(stack_a, stack_b);
    else if (!strcmp(operation, "pa"))
        push(stack_a, stack_b);
    else if (!strcmp(operation, "pb"))
        push(stack_b, stack_a);
    else if (!strcmp(operation, "ra"))
        rotate_a_or_b(stack_a);
    else if (!strcmp(operation, "rb"))
        rotate_a_or_b(stack_b);
    else if(!strcmp(operation, "rr"))
        rotate_ab(stack_a, stack_b);
    else if (!strcmp(operation, "rra"))
        reverse_rotate_a_or_b(stack_a);
    else
        display_err_exit();
}

int main(int argc, char *argv[])
{
    t_stack stacks[2];
    char **line;

    if (argc <= 1)
        exit(EXIT_FAILURE);
    check_for_int_and_overflow(argc, argv);
    check_for_duplicates(argc, argv);
    initialize_stack(&(stacks[A]), argc - 1, 'a');
    populate_stack(argc, argv, &(stacks[A]));
    initialize_stack(&(stacks[B]), argc - 1, 'b');

    print_stack(&(stacks[A]));
    print_stack(&(stacks[B]));

    while (get_next_line(0, line))
        execute_operations(&(stacks[A]), &(stacks[B]), *line);

    print_stack(&(stacks[A]));
    print_stack(&(stacks[B]));

    if (is_sorted(&(stacks[A])) && stacks[B].top == 0)
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
    return (0);
}