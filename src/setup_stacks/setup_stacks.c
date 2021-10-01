#include "../push_swap.h"
#include "setup_stacks.h"
#include "../error_checks/error_checks.h"

void populate_stack(char *argv[], t_stack *stack)
{
    int i;
    int x;
    int j;

    i = 1;
    j = stack->len - 1;
    while (argv[i] != NULL) // MOET JE VERVANGEN DOOR ARGC! Op sommige systemen kan eerste argument van ARGV NULL zijn, als programma naam niet gelezen kan worden
    {
        x = ft_strtoi(argv[i]);
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