#include "push_swap.h"

/*
Als het grootste getal op top staat, verspilt het algoritme veel moves.
Het vergelijkt met elk ander getal en rotate door tot het klaar is.
In deze staat is de stack hetzelfde als voor het algoritme begon.
Dan roteert ie uit. 

check of het grootste getal op plek top -1 of top - 2 zit, zo ja roteer em eruit, zo nee ga door
*/

void bubble_sort(t_stack *stack_a)
{
    int j = 0;
    int k = 0;
    int l = stack_a->top - 1;
    int m = 0;
    int index_last_element = stack_a->top - 1;
    int index_second_last_element = stack_a->top - 2;

    // if (is_sorted(stack_a))
        // return (0);

    while (j < stack_a->top - 1)
    {
        while (k < l)
        {
            if (stack_a->p_array[index_last_element] > stack_a->p_array[index_second_last_element])
                swap_a_or_b(stack_a);
            if (l > 1)
    			rotate(stack_a);
            k++;
        }
        if (j < stack_a->top - 1 - 1)
        {
            while (m < j + 1)
            {
                rotate(stack_a);
                m++;
            }
        }
        m = 0;
        k = 0;
        l--;
        j++;
    }
}

// void bubble_sort(t_stack *stack_a)
// {
//     int i;
//     int j;
//     int index_last_element;
//     int index_second_last_element;

//     i = 0;
//     j = 0;
//     index_last_element = stack_a->top - 1;
//     index_second_last_element = stack_a->top - 2;

//     while (i < stack_a->top - 1) // looped over elk getal in de stack
//     {
//         // vergelijk elk getal met elk ander getal behalve zichzelf, dus n - 1 keer
//         while (j < stack_a->top - 1)
//         {
//             if (stack_a->p_array[index_last_element] > stack_a->p_array[index_second_last_element])
//             {
//                 swap_a_or_b(stack_a);
//                 rotate(stack_a);
//             }
//             j++;
//         }
//         i++;
//     }
// }

void sort_three(t_stack *stack)
{
    int minimum;

    minimum = get_minimum(stack);
    if (is_ordered(stack))
    {
        rotate_to_top(stack, minimum);
        #ifdef DEBUG
            printf("sort_three() = \n");
            print_stack(stack);
        #endif
        return;
    }
    rotate_to_top_minus_one(stack, minimum);
    swap_a_or_b(stack);
    #ifdef DEBUG
        printf("sort_three() = \n");
        print_stack(stack);
    #endif
}

void split_stack_ab(t_stack *stack_a, t_stack *stack_b)
{
    int average = get_average(stack_a);

    int x;
    int i = 0;
    int top_dup = stack_a->top;
    int index_to_check = stack_a->top - 1 - i;

    while (i < top_dup)
    {
        if (stack_a->p_array[index_to_check - i] > average)
        {
            x = rotate_to_top(stack_a, stack_a->p_array[index_to_check - i]);
            push(stack_a, stack_b);
            index_to_check = index_to_check + x;
        }
        i++;
    }
    #ifdef DEBUG
        print_stack(stack_a);
        print_stack(stack_b);
    #endif
}