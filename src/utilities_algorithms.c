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

void split_stack_ab(t_stack *stack_a, t_stack *stack_b)
{
    int i;
    int maximum;
    int elements_to_push;

    i = 0;
    elements_to_push = (stack_a->top - 1) / 2;
    while (i < elements_to_push)
    {
        maximum = get_maximum(stack_a);
        rotate_to_top(stack_a, maximum);
        push(stack_a, stack_b);
        i++;
    }
}

void _oud_split_stack_ab(t_stack *stack_a, t_stack *stack_b)
{
    int average = get_average(stack_a);

    int x;
    int i = 0;
    int top_dup = stack_a->top;
    int index_to_check = stack_a->top - 1 - i;

    while (i < top_dup)
    {
        if (stack_a->p_array[index_to_check - i] > average)
        {
            x = rotate_to_top(stack_a, stack_a->p_array[index_to_check - i]);
            push(stack_a, stack_b);
            index_to_check = index_to_check + x;
        }
        i++;
    }
    #ifdef DEBUG
        print_stack(stack_a);
        print_stack(stack_b);
    #endif
}