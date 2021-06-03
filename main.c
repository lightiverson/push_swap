#include "push_swap.h"

void print_stack(void)
{

}

void populate_stack(char *argv[], t_stack *stack)
{
    int i;
    int x;
    int j;

    i = 1;
    j = 0;
    while (argv[i] != NULL) // Is het niet beter deze te vervangen door argc, aangezien array size daarop gebaseerd is?
    {
        x = ft_atoi(argv[i]);
        stack->p_array[j] = x;
        j++;
        i++;
    }
}

void instantiate_stack(t_stack *stack, int len)
{
    stack->p_array = malloc(sizeof(*stack->p_array) * len);
    if (stack->p_array == NULL)
    {
        ft_putstr_fd("malloc failed\n", 1);
        exit(EXIT_FAILURE);
    }
    stack->top = 0;
}

int main(int argc, char *argv[])
{
    ft_putstr_fd("running main()\n", 1);
    push_swap();

    t_stack stack_a; // Declare variable stack_a of type t_stack

    instantiate_stack(&stack_a, argc);
    ft_putnbr_fd(stack_a.top, 1);

    populate_stack(argv, &stack_a);
    ft_putnbr_fd(stack_a.p_array[0], 1);
    ft_putnbr_fd(stack_a.p_array[1], 1);
    ft_putnbr_fd(stack_a.p_array[2], 1);

    free(stack_a.p_array);
    return (0);
}

// int main(int argc, char *argv[])
// {
//     ft_putstr_fd("running main()\n", 1);
//     push_swap();

//     printf("*argv = %s", *argv); // name of the executable
//     printf("*(argv[2]) = %s", (argv[2])); // name of the executable
//     return (0);
// }