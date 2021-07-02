#include "push_swap.h"

bool is_sorted(t_stack *stack)
{
    int i;
    int j;

    i = stack->top - 1;
    j = stack->top - 2;
    while (j > -1)
    {
		if (stack->p_array[j] < stack->p_array[i])
			return false;
		i--;
        j--;
    }
    return true;
}

int get_minimum(const int *p_array, int top)
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
    return minimum;
}

int get_maximum(const int *p_array, int top)
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

int get_index(const int *p_array, int array_len, int x)
{
    int i;
    int index;

    i = 0;
    index = -1;
    while (i < array_len)
    {
        if (x == p_array[i])
            index = i;
        i++;
    }
    return index; 
}

bool is_in_array(const int *p_array, int array_len, int x)
{
    int i;

    i = 0;
    while (i < array_len)
    {
        if (x == p_array[i])
            return true;
        i++;
    }
    return false;
}