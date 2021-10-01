#include "../push_swap.h"

void display_err_exit(void)
{
    write(STDERR_FILENO, "Error\n", 6);
    exit(EXIT_FAILURE);
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

void check_duplicate(t_stack *stack)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < stack->top)
    {
        while (j < stack->top)
        {
            if (i == j)
                continue;
            if (stack->p_array[i] == stack->p_array[j])
                display_err_exit();
            j++;
        }
        i++;
    }
}