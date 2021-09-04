#include "../push_swap.h"
#include "../operations/operations.h"
#include "algorithms.h"

void sort_five(t_stack *stack_a, t_stack *stack_b)
{
    ;
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
        free(p_distance_array);
        return (insert_value);
    }

    if (origin > get_maximum(stack))
    {
        insert_value = get_maximum(stack);
        printf("%d should be pushed on top of %d\n", origin, insert_value);
        free(p_distance_array);
        return (insert_value);
    }

    insert_value = get_minimum_positive(stack, p_distance_array);
    printf("%d should be pushed on top of %d\n", origin, insert_value);
    free(p_distance_array);
    return (insert_value);
}

// 1 5 2 4 3
// pb + pb
// 2 4 3
// 5 1
// rra + sa
// 2 3 4
// 5 1
// pb
// 5 2 3 4
// 1
// ra + pb
// 1 2 3 4 5
