#include "../push_swap.h"
#include "../operations/operations.h"
#include "algorithms.h"

void sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int minimum;

    minimum = get_minimum(stack_a);
	if (is_ordered(stack_a))
	{
		rotate_to_top(stack_a, minimum);
		return;
	}
    split_stack_ab(stack_a, stack_b);

    print_stack(stack_a);
    print_stack(stack_b);
    printf("is_sorted = %d\n", is_sorted(stack_b));

	sort_three(stack_a, stack_b);
	while (stack_b->top)
		push(stack_b, stack_a);
	if (!is_ordered(stack_a))
		rotate_to_top(stack_a, minimum);
}

int *create_distance_array(t_stack *stack, int origin)
{
    int i;
    int *p_distance_array;

    p_distance_array = malloc(sizeof(*p_distance_array) * stack->len);

    if (p_distance_array == NULL)
    {
        #ifdef DEBUG
            printf("malloc failed\n");
        #endif
        exit(EXIT_FAILURE);
    }

    i = 0;
    while (i < stack->len)
    {
        p_distance_array[i] = stack->p_array[i] - origin;
		#ifdef DEBUG
            printf("p_distance_array[%d] = %d\n", i, p_distance_array[i]);
        #endif
        i++;
    }

    return p_distance_array;
}

int get_minimum_positive(const t_stack *stack, int *p_distance_array)
{
    int i;
    int minimum_positive;

    i = 0;
    while ((i < stack->top) && (p_distance_array[i] < 0))
        i++;

    if (i == stack->top)
    {
        #ifdef DEBUG
            printf("No positive number found. Return -1.");
        #endif
        return (-1);
    }
    
    minimum_positive = stack->p_array[i];
    i++;

    while (i < stack->top)
    {
        if ((p_distance_array[i] < minimum_positive) && (p_distance_array[i] > -1))
            minimum_positive = stack->p_array[i];
        i++;
    }

    #ifdef DEBUG
        printf("get_minimum_positive() = %d\n", minimum_positive);
    #endif

    return minimum_positive;
}

int get_insert_value(t_stack *stack, int origin)
{
    int insert_value;
    int *p_distance_array;

    p_distance_array = create_distance_array(stack, origin);

    if (origin < get_minimum(stack))
    {
        insert_value = get_minimum(stack);
        printf("%d should be pushed on top of %d\n", origin, insert_value);
        return (insert_value);
    }

    if (origin > get_maximum(stack))
    {
        insert_value = get_maximum(stack);
        printf("%d should be pushed on top of %d\n", origin, insert_value);
        return (insert_value);
    }

    insert_value = get_minimum_positive(stack, p_distance_array);
    printf("%d should be pushed on top of %d\n", origin, insert_value);
    return (insert_value);
}