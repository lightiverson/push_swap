#include "push_swap.h"

int swap(t_stack *stack)
{
    int temp;

    if (stack->top < 2)
    {
        printf("Less than 2 elements. Do nothing. Return");
        return (1);
    }

    temp = stack->p_array[stack->top - 1];
    stack->p_array[stack->top - 1] = stack->p_array[stack->top - 2];
    stack->p_array[(stack->top) - 2] = temp;
    return (0);
}

void print_stack(t_stack *stack)
{
    int i;

    i = 0;
    printf("stack->len = %d\n", stack->len);
    printf("stack->top = %d\n", stack->top);
    while (i < stack->len)
    {
        printf("%d\n", stack->p_array[i]);
        i++;
    }
    printf("-\n");
}

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

void initialize_stack(t_stack *stack, int len)
{
    stack->p_array = ft_calloc(len,sizeof(*stack->p_array));
    if (stack->p_array == NULL)
    {
        ft_putstr_fd("malloc failed\n", 1);
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

    swap(&(stacks[0]));
    print_stack(&(stacks[0]));

    return (0);
}