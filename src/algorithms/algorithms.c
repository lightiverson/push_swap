#include "../push_swap.h"
#include "../operations/operations.h"

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
    			rotate_a_or_b(stack_a);
            k++;
        }
        if (j < stack_a->top - 1 - 1)
        {
            while (m < j + 1)
            {
                rotate_a_or_b(stack_a);
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