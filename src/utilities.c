#include "push_swap.h"
#include "./error_checks/error_checks.h"

void print_stack(const t_stack *stack)
{
    int i;

    i = stack->top;
    printf("stack->name = %c\n", stack->stack_name);
    while (i)
    {
        printf("[%d] = %d\n", i - 1, stack->p_array[i - 1]);
        i--;
    }
    printf("----\n");
}

void free_stacks(t_stack *stack_a, t_stack *stack_b)
{
    free(stack_a->p_array);
    free(stack_b->p_array);
}

static void handle_negative(int *p_number, int *p_digit)
{
    if ((*p_number > INT_MAX / 10) || ((*p_number == INT_MAX / 10) && (*p_digit > INT_MAX % 10)))
        display_err_exit();
    *p_number = (*p_number * 10) + *p_digit;
}

static void handle_positive(int *p_number, int *p_digit)
{
    if ((*p_number < INT_MIN / 10) || ((*p_number == INT_MIN / 10) && (*p_digit > (INT_MIN % 10) * -1)))
        display_err_exit();
    *p_number = (*p_number * 10) - *p_digit;
}

int ft_strtoi(const char *str)
{
    bool is_negative;
    int number;
    int digit;

    if (*str == '-')
    {
        is_negative = true;
        str++;
    }
    number = 0;
    digit = 0;
    if (*str == '\0')
        display_err_exit();
    while (*str)
    {
        if (!ft_isdigit(*str))
            display_err_exit();
        digit = *str - '0';
        if (!is_negative)
            handle_negative(&number, &digit);
        else
            handle_positive(&number, &digit);
        str++;
    }
    return (number);
}

// een empty string is een string met alleen een \0 character erin. Dus de while loop stopt vroegtijdig.
// de while loop moet een andere conditional hebben dan \0????
