#include "push_swap.h"

void populate_stack(char *argv[], t_stack *stack)
{
    printf("running populate_stack()\n");
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

void initialize_stack(t_stack *stack, int len)
{
    printf("running initialize_stack()\n");
    stack->p_array = ft_calloc(len,sizeof(*stack->p_array));
    if (stack->p_array == NULL)
    {
        printf("malloc failed\n");
        exit(EXIT_FAILURE);
    }
    stack->top = 0;
    stack->len = len;
}

int main(int argc, char *argv[])
{
    printf("running main()\n");
    push_swap();

    int i;

    i = 0;
    t_stack stacks[2];

    while (i < 2)
    {
        initialize_stack(&(stacks[i]), argc - 1);
        i++;
    }

    populate_stack(argv, &(stacks[0]));

    print_stack(&(stacks[0]));
    print_stack(&(stacks[1]));

    // swap(&(stacks[0]));

    // push(&(stacks[0]), &(stacks[1]));

    rotate(&(stacks[0]));
    reverse_rotate(&(stacks[0]));

    return (0);
}