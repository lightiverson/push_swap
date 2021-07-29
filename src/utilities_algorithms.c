#include "push_swap.h"

int rotate_to_top(t_stack *stack, int element)
{
    int number_of_rotations;
    int index_element;
    int middle_of_stack;

    number_of_rotations = 0;
    index_element = get_index(stack, element);
    middle_of_stack = (stack->top - 1) / 2;
    while (get_index(stack, element) != stack->top - 1)
    {
        if (index_element < middle_of_stack)
            reverse_rotate(stack);
        else
            rotate(stack);
        number_of_rotations++;
    }
    return (number_of_rotations);
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