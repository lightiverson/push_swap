#include "push_swap.h"

void print_stack(t_stack *stack)
{
    int i;

    i = stack->top;
    printf("stack->len = %d\n", stack->len);
    printf("stack->top = %d\n", stack->top);
    printf("stack->name = %c\n", stack->stack_name);
    while (i)
    {
        printf("[%d] = %d\n", i - 1, stack->p_array[i - 1]);
        i--;
    }
    printf("----\n");
}

int minimum(int *p_array, int top)
{
    int i;
    int minimum;

    i = 0;
    minimum = p_array[i];
    while (i < top)
    {
        if (p_array[i] < minimum)
        {
            minimum = p_array[i];
        }
        i++;
    }

    return minimum;
}

// Ik shift mijn array, dus je moet altijd vanaf de bodem
int index_of_minimum(int *p_array, int top)
{
    int i;
    int index_of_minimum;

    i = 0;
    index_of_minimum = 0;
    while (i < top)
    {
        if (p_array[i] < p_array[index_of_minimum])
        {
            index_of_minimum = i;
        }
        i++;
    }

    return index_of_minimum;
}

void selection_sort(t_stack *stack_a, t_stack *stack_b)
{
    int min_index;
    int cutoff;

    min_index = index_of_minimum(stack_a->p_array, stack_a->top);
    cutoff = (stack_a->top - 1) / 2;
    while (index_of_minimum(stack_a->p_array, stack_a->top) != (stack_a->top - 1))
    {
        if (min_index < cutoff)
            reverse_rotate(stack_a);
        else
            rotate(stack_a);
    }
    push(stack_a, stack_b);
}