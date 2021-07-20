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
                swap(stack_a);
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
//                 swap(stack_a);
//                 rotate(stack_a);
//             }
//             j++;
//         }
//         i++;
//     }
// }

int back_inbound(const t_stack *stack_a, int index)
{
    if (index == -1)
        return stack_a->top - 1;
    return index;
}

bool is_ordered(const t_stack *stack)
{
    int i = 0;
	int minimum = get_minimum(stack->p_array, stack->top);
	int index_minimum = get_index(stack->p_array, stack->len, minimum);
	int one_down = back_inbound(stack, index_minimum - 1);
    int two_down = back_inbound(stack, one_down - 1);

    while (i < stack->top - 1 - 1)
    {
        #ifdef DEBUG
            printf("iteratie %d\n", i);
            printf("if (a[%d] > a[%d])\n", stack->p_array[one_down], stack->p_array[two_down]);
        #endif
        if (stack->p_array[one_down] > stack->p_array[two_down])
        {
            #ifdef DEBUG
                printf("returned false\n");
            #endif
            return false;
        }
        one_down = two_down;
        two_down = back_inbound(stack, one_down) - 1;
        i++;
    }
    #ifdef DEBUG
        printf("returned true\n");
    #endif
    return true;
}

void sort_three(t_stack *stack)
{
    int minimum;

    minimum = get_minimum(stack->p_array, stack->top);
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
    swap(stack);
    #ifdef DEBUG
        printf("sort_three() = \n");
        print_stack(stack);
    #endif
}