#include "push_swap.h"

int get_minimum(const t_stack *stack)
{
    int i;
    int minimum;

    i = 1;
    minimum = stack->p_array[0];
    while (i < stack->top)
    {
        if (stack->p_array[i] < minimum)
            minimum = stack->p_array[i];
        i++;
    }
    #ifdef DEBUG
        printf("get_minimum() = %d\n", minimum);
    #endif
    return minimum;
}

int get_maximum(const t_stack *stack)
{
    int i;
    int maximum;

    i = 1;
    maximum = stack->p_array[0];
    while (i < stack->top)
    {
        if (stack->p_array[i] > maximum)
            maximum = stack->p_array[i];
        i++;
    }
    return maximum;
}

int get_average(const t_stack *stack)
{
    int minimum = get_minimum(stack);
    int maximum = get_maximum(stack);
    int average;

    average = (minimum + maximum) / 2;
    return average;
}

int get_index(const t_stack *stack, int element)
{
    int i;
    int index_element;

    i = 0;
    index_element = -1;
    while (i < stack->top)
    {
        if (element == stack->p_array[i])
            index_element = i;
        i++;
    }
    #ifdef DEBUG
        printf("get_index() = %d\n", index_element);
    #endif
    return index_element; 
}