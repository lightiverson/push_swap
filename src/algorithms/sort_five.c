#include "../push_swap.h"
#include "../operations/operations.h"
#include "algorithms.h"

static int *create_distance_array(const t_stack *stack, int origin)
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

static int get_minimum_positive(const t_stack *stack, int *p_distance_array)
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
        if ((stack->p_array[i] < minimum_positive) && (p_distance_array[i] > -1))
            minimum_positive = stack->p_array[i];
        i++;
    }

    #ifdef DEBUG
        printf("get_minimum_positive() = %d\n", minimum_positive);
    #endif

    return minimum_positive;
}

static int get_insert_value(const t_stack *destination_stack, int origin)
{
    int insert_value;
    int *p_distance_array;

    p_distance_array = create_distance_array(destination_stack, origin);

    if (origin < get_minimum(destination_stack))
    {
        insert_value = get_minimum(destination_stack);
        #ifdef DEBUG
            printf("%d should be pushed on top of %d\n", origin, insert_value);
        #endif
        free(p_distance_array);
        return (insert_value);
    }

    if (origin > get_maximum(destination_stack))
    {
        // insert_value = get_maximum(destination_stack);
        insert_value = get_minimum(destination_stack);
        #ifdef DEBUG
            printf("%d should be pushed on top of %d\n", origin, insert_value);
        #endif
        free(p_distance_array);
        return (insert_value);
    }

    insert_value = get_minimum_positive(destination_stack, p_distance_array);
    #ifdef DEBUG
        printf("%d should be pushed on top of %d\n", origin, insert_value);
    #endif
    free(p_distance_array);
    return (insert_value);
}

static void insert_into_stack(t_stack *origin_stack, t_stack *destination_stack)
{
    int insert_value;

    insert_value = get_insert_value(destination_stack, origin_stack->p_array[origin_stack->top - 1]); // = 48 moet 47 zijn
    // Is er een case waarbij de insert_value niet correct gevonden kan worden? Zo ja wat doe je dan?
    rotate_to_top(destination_stack, insert_value);
    push(origin_stack, destination_stack);
}

void sort_five(t_stack *stack_a, t_stack *stack_b)
{
    #ifdef DEBUG
        printf("sort_five()\n");
    #endif

    // Protection voor deze functie?
    if (stack_a->top < 4 && stack_a->top > 5)
    {
        printf("stack_a->top = %d\n", stack_a->top);
        printf("Stack A's N is smaller than 4 OR larger than 5\n");
        printf("Program error: wrong algo used on N size stack");
        exit(EXIT_FAILURE);
    }

    push(stack_a, stack_b);
    push(stack_a, stack_b);
    sort_three(stack_a);
    insert_into_stack(stack_b, stack_a);
    insert_into_stack(stack_b, stack_a);
    rotate_to_top(stack_a, get_minimum(stack_a));
}