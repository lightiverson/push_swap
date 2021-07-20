#include "push_swap.h"

bool is_sorted(t_stack *stack)
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

int get_minimum(const int *p_array, int top) // *p_array en top zitten beiden in dezelfde struct
{
    int i;
    int minimum;

    i = 1;
    minimum = p_array[0];
    while (i < top)
    {
        if (p_array[i] < minimum)
            minimum = p_array[i];
        i++;
    }
    #ifdef DEBUG
        printf("get_minimum() = %d\n", minimum);
    #endif
    return minimum;
}

int get_maximum(const int *p_array, int top) // *p_array en top zitten beiden in dezelfde struct
{
    int i;
    int maximum;

    i = 1;
    maximum = p_array[0];
    while (i < top)
    {
        if (p_array[i] > maximum)
            maximum = p_array[i];
        i++;
    }
    return maximum;
}

int get_index(const int *p_array, int top, int element) // *p_array en top zitten beiden in dezelfde struct
{
    int i;
    int index_element;

    i = 0;
    index_element = -1;
    while (i < top)
    {
        if (element == p_array[i])
            index_element = i;
        i++;
    }
    #ifdef DEBUG
        printf("get_index() = %d\n", index_element);
    #endif
    return index_element; 
}

bool is_in_array(const int *p_array, int top, int x) // *p_array en top zitten beiden in dezelfde struct
{
    int i;

    i = 0;
    while (i < top)
    {
        if (x == p_array[i])
            return true;
        i++;
    }
    return false;
}

void rotate_to_top(t_stack *stack, int element)
{
    int index_element;
    int middle_of_stack;
    
    index_element = get_index(stack->p_array, stack->len, element);
    middle_of_stack = (stack->top - 1) / 2;
    while (get_index(stack->p_array, stack->len, element) != stack->top - 1)
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

    index_element = get_index(stack->p_array, stack->len, element);
    middle_of_stack = (stack->top - 1) / 2;
    while (get_index(stack->p_array, stack->len, element) != stack->top - 2)
    {
        if (index_element > middle_of_stack)
            reverse_rotate(stack);
        else
            rotate(stack);
    }
}