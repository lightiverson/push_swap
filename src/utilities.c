#include "push_swap.h"

void print_stack(const t_stack *stack)
{
    int i;

    i = stack->top;
    printf("stack->name = %c\n", stack->stack_name);
    while (i)
    {
        printf("[%d] = %d\n", i - 1, stack->p_array[i - 1]);
        i--;
    }
    printf("----\n");
}

void free_stacks(t_stack *stack_a, t_stack *stack_b)
{
    free(stack_a->p_array);
    free(stack_b->p_array);
}

// void print_stack(const t_stack *stack)
// {
//     int i;

//     i = 0;
//     printf("stack->name = %c\n", stack->stack_name);
//     while (i < stack->top)
//     {
//         printf("%d", stack->p_array[i]);
//         if (i != stack->top - 1)
//             printf(", ");
//         i++;
//     }
//     printf("\n----\n");
// }