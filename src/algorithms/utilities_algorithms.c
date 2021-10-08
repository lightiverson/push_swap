#include "../push_swap.h"

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
            reverse_rotate_a_or_b(stack);
        else
            rotate_a_or_b(stack);
        number_of_rotations++;
    }
    return (number_of_rotations);
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