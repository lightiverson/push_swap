#include "push_swap.h"

void print_stack(t_stack *stack)
{
    int i;

    i = 0;
    printf("stack->len = %d\n", stack->len);
    printf("stack->top = %d\n", stack->top);
    while (i < stack->len)
    {
        printf("%d\n", stack->p_array[i]);
        i++;
    }
    printf("-\n");
}

void populate_stack(char *argv[], t_stack *stack)
{
    int i;
    int x;
    int j;

    i = 1;
    j = 0;
    while (argv[i] != NULL) // Is het niet beter deze te vervangen door argc, aangezien array size daarop gebaseerd is?
    {
        x = ft_atoi(argv[i]);
        stack->p_array[j] = x;
        j++;
        i++;
    }
}

void initialize_stack(t_stack *stack, int len)
{
    stack->p_array = ft_calloc(len,sizeof(*stack->p_array));
    if (stack->p_array == NULL)
    {
        ft_putstr_fd("malloc failed\n", 1);
        exit(EXIT_FAILURE);
    }
    stack->top = 0;
    stack->len = len;
}

// int main(int argc, char *argv[])
// {
//     ft_putstr_fd("running main()\n", 1);
//     push_swap();

//     t_stack stack_a; // Declare variable stack_a of type t_stack

//     initialize_stack(&stack_a, argc - 1); // - 1 because argc includes a count for the name of the executable

//     populate_stack(argv, &stack_a);

//     print_stack(&stack_a);

//     free(stack_a.p_array);
//     return (0);
// }

int main(int argc, char *argv[])
{
    printf("running main()\n");
    push_swap();

    t_stacks stacks;

    initialize_stack(&(stacks.stack_a), argc - 1); // - 1 because argc includes a count for the name of the executable
    initialize_stack(&(stacks.stack_b), argc - 1); // - 1 because argc includes a count for the name of the executable

    populate_stack(argv, &(stacks.stack_a));

    print_stack(&(stacks.stack_a));
    print_stack(&(stacks.stack_b));

    free(stacks.stack_a.p_array);
    free(stacks.stack_b.p_array);
    return (0);
}