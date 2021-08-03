#include "../push_swap.h"

int push(t_stack *stack_from, t_stack *stack_to)
{
    int first_element;

    if (stack_from->top == 0)
    {
        printf("Stack_from is empty! Return error.\n");
        return (1);
    }

    first_element = stack_from->p_array[stack_from->top -1];
    stack_from->top--;

    stack_to->p_array[stack_to->top] = first_element;
    stack_to->top++;

    printf("p%c\n", stack_from->stack_name);

    return (0);
}
