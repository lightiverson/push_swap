#include "push_swap.h"

void print_stack(t_stack *stack)
{
    int i;

    i = 0;
    printf("stack->len = %d\n", stack->len);
    printf("stack->top = %d\n", stack->top);
    while (i < stack->top)
    {
        printf("[%d] = %d\n", i, stack->p_array[i]);
        i++;
    }
    printf("----\n\n");
}