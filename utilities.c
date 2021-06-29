#include "push_swap.h"

int minimum(int *p_array, int top)
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
        printf("minimum = %d\n", minimum);
    #endif
    return minimum;
}

int index_of_value(const int *p_array, int array_len, int x)
{
    int i;
    int index_of_value;

    i = 0;
    index_of_value = -1;
    while (i < array_len)
    {
        if (x == p_array[i])
            index_of_value = i;
        i++;
    }
    #ifdef DEBUG
        printf("index_of_value = %d\n", index_of_value);
    #endif
    return index_of_value; 
}

bool is_in_array(const int *p_array, int array_len, int x)
{
    #ifdef DEBUG
        printf("running is_in_array()\n");
    #endif
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

int find_next_smallest_value(const int *p_array, int array_len, int *p_array_exclude, int array_exclude_len)
{
    // die exclude array moet je in deze functie maken. misschien eerst als variable size array voor testing purposes. En dan later mallocen
    int array_exclude[array_len];
    #ifdef DEBUG
        printf("running find_next_smallest_value()\n");
    #endif
    int i;
    int smallest_value;

    i = 1;
    smallest_value = p_array[0];
    while (i < array_len)
    {
        if (p_array[i] < smallest_value)
        {
            if (is_in_array(p_array_exclude, array_exclude_len, p_array[i]))
            {
                i++;
                continue;
            }
            smallest_value = p_array[i];
        }
        i++;
    }
    #ifdef DEBUG
        printf("smallest_value = %d\n", smallest_value);
    #endif
    return smallest_value;
}

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

int find_largest_value(int *p_array, int top)
{
    int i;
    int largest_value;

    i = 1;
    largest_value = p_array[0];
    while (i < top)
    {
        if (p_array[i] > largest_value)
            largest_value = p_array[i];
        i++;
    }
    #ifdef DEBUG
        printf("largest_value = %d\n", largest_value);
    #endif
    return largest_value;
}

void alpha(t_stack *stack_a)
{
    printf("running alpha()\n");

    int j = 0;
    int k = 0;
    int l = stack_a->top - 1; // 4
    int m = 0;
    int index_last_element = stack_a->top - 1;
    int index_second_last_element = stack_a->top - 2;

    while (j < stack_a->top - 1) // deze loopt 6x
    {
        while (k < l) // deze loopt de eerste iteratie 5x, de volgende iteratie 4x
        {
            if (stack_a->p_array[index_last_element] > stack_a->p_array[index_second_last_element])
            {
                swap(stack_a);
                rotate(stack_a);
            }
            else
                rotate(stack_a);
            k++;
        }
        while (m < j + 1) // Je moet em nog eruit roteren. de eerste iteratie 1x, de volgende iteratie 2x, de vijfde iteratie 6x
        {
            rotate(stack_a);
            m++;
        }
        m = 0;
        k = 0;
        l--;
        j++;
        print_stack(stack_a);
    }
}