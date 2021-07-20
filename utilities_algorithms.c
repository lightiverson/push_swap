#include "push_swap.h"

bool is_sorted(const t_stack *stack)
{
    int i;
    int j;

    i = stack->top - 1;
    j = stack->top - 2;
    if (stack->top == 1)
        return true;
    while (j > -1)
    {
		if (stack->p_array[j] < stack->p_array[i])
			return false;
		i--;
        j--;
    }
    return true;
}

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

bool is_in_array(const t_stack *stack, int x)
{
    int i;

    i = 0;
    while (i < stack->top)
    {
        if (x == stack->p_array[i])
            return true;
        i++;
    }
    return false;
}

void rotate_to_top(t_stack *stack, int element)
{
    int index_element;
    int middle_of_stack;
    
    index_element = get_index(stack, element);
    middle_of_stack = (stack->top - 1) / 2;
    while (get_index(stack, element) != stack->top - 1)
    {
        if (index_element < middle_of_stack)
            reverse_rotate(stack);
        else
            rotate(stack);
    }
}

void rotate_to_top_minus_one(t_stack *stack, int element)
{
    int index_element;
    int middle_of_stack;

    index_element = get_index(stack, element);
    middle_of_stack = (stack->top - 1) / 2;
    while (get_index(stack, element) != stack->top - 2)
    {
        if (index_element > middle_of_stack)
            reverse_rotate(stack);
        else
            rotate(stack);
    }
}