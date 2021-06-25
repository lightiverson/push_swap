#include "push_swap.h"

void populate_stack(char *argv[], t_stack *stack)
{
    int i;
    int x;
    int j;

    i = 1;
    j = stack->len - 1;
    while (argv[i] != NULL) // Is het niet beter deze te vervangen door argc, aangezien array size daarop gebaseerd is?
    {
        x = ft_atoi(argv[i]);
        stack->p_array[j] = x;
        stack->top++;
        j--;
        i++;
    }
}

void initialize_stack(t_stack *stack, int len, char stack_name)
{
    stack->p_array = ft_calloc(len, sizeof(*stack->p_array));
    if (stack->p_array == NULL)
    {
        printf("malloc failed\n");
        exit(EXIT_FAILURE);
    }
    stack->top = 0;
    stack->len = len;
    stack->stack_name = stack_name;
}

int main(int argc, char *argv[])
{
    t_stack stacks['c'];
    initialize_stack(&(stacks['a']), argc - 1, 'a');
    populate_stack(argv, &(stacks['a']));
    initialize_stack(&(stacks['b']), argc - 1, 'b');
    
    print_stack(&(stacks['a']));
    print_stack(&(stacks['b']));

    // selection_sort(&(stacks['a']), &(stacks['b']));
    // selection_sort(&(stacks['a']), &(stacks['b']));
    // selection_sort(&(stacks['a']), &(stacks['b']));
    // selection_sort(&(stacks['a']), &(stacks['b']));

    // printf("\n\n");
    // print_stack(&(stacks['a']));
    // print_stack(&(stacks['b']));
    // bubble_sort(&(stacks['a']));
    // print_stack(&(stacks['a']));

    // minimum(stacks['a'].p_array, stacks['a'].top);

    // is_in_array(stacks['a'].p_array, stacks['a'].len, 66);

    // int array_test[] = {6, 9};
    // find_next_smallest_value(stacks['a'].p_array, stacks['a'].len, array_test, 2);
    // index_of_value(stacks['a'].p_array, stacks['a'].len, 9);

    // 3 2 5 1 6 4
    // find_largest_value(stacks['a'].p_array, stacks['a'].top);

    alpha(&stacks['a']);
    return (0);
}