#include "push_swap.h"

void bubble_sort(t_stack *stack_a)
{
    int j = 0;
    int k = 0;
    int l = stack_a->top - 1;
    int m = 0;
    int index_last_element = stack_a->top - 1;
    int index_second_last_element = stack_a->top - 2;

    while (j < stack_a->top - 1)
    {
        while (k < l)
        {
            if (stack_a->p_array[index_last_element] > stack_a->p_array[index_second_last_element])
                swap(stack_a);
			rotate(stack_a);
            k++;
        }
		while (m < j + 1)
		{
			rotate(stack_a);
			m++;
		}
        m = 0;
        k = 0;
        l--;
        j++;
    }
}