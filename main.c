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

// int main(int argc, char *argv[])
// {
//     int i;

//     i = 0;
//     t_stack stacks[2];
//     while (i < 2)
//     {
//         initialize_stack(&(stacks[i]), argc - 1);
//         i++;
//     }
//     populate_stack(argv, &(stacks[0]));
//     print_stack(&(stacks[0]));
//     print_stack(&(stacks[1]));

//     swap(&(stacks[0]));
//     push(&(stacks[0]), &(stacks[1]));
//     rotate(&(stacks[0]));
//     reverse_rotate(&(stacks[0]));
//     minimum(stacks[0].p_array, stacks[0].len);
//     index_of_minimum(stacks[0].p_array, stacks[0].len);

//     selection_sort(&(stacks[0]), &(stacks[1]));
//     selection_sort(&(stacks[0]), &(stacks[1]));

//     minimum(stacks[0].p_array, stacks[0].top);
//     push(&(stacks[0]), &(stacks[1]));
//     minimum(stacks[0].p_array, stacks[0].top);

//     selection_sort(&(stacks[0]), &(stacks[1]));
//     push(&(stacks[0]), &(stacks[1]));
//     selection_sort(&(stacks[0]), &(stacks[1]));
//     selection_sort(&(stacks[0]), &(stacks[1]));
//     selection_sort(&(stacks[0]), &(stacks[1]));
//     selection_sort(&(stacks[0]), &(stacks[1]));
//     selection_sort(&(stacks[0]), &(stacks[1]));

//     return (0);
// }

int main(int argc, char *argv[])
{
    t_stack stacks['c'];
    initialize_stack(&(stacks['a']), argc - 1, 'a');
    populate_stack(argv, &(stacks['a']));
    initialize_stack(&(stacks['b']), argc - 1, 'b');
    
    // print_stack(&(stacks['a']));
    // print_stack(&(stacks['b']));

    selection_sort(&(stacks['a']), &(stacks['b']));
    selection_sort(&(stacks['a']), &(stacks['b']));
    selection_sort(&(stacks['a']), &(stacks['b']));
    selection_sort(&(stacks['a']), &(stacks['b']));

    printf("\n\n");
    print_stack(&(stacks['a']));
    print_stack(&(stacks['b']));

    return (0);
}