#include "../push_swap.h"

int push(t_stack *origin_stack, t_stack *destination_stack)
{
    int first_element;

    if (origin_stack->top == 0)
    {
        printf("Stack_from is empty! Return error.\n");
        return (1);
    }

    first_element = origin_stack->p_array[origin_stack->top -1];
    origin_stack->top--;

    destination_stack->p_array[destination_stack->top] = first_element;
    destination_stack->top++;

    printf("p%c\n", origin_stack->stack_name);

    return (0);
}
