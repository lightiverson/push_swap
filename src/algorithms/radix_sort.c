#include "./algorithms.h"

void copy_stack_a_b(t_stack *stack_a, t_stack *stack_b)
{
	printf("Running copy_stack_a_b()\n");
	int i;

	i = 0;
	while (i < stack_a->top)
	{
		stack_b->p_array[i] = stack_a->p_array[i];
		i++;
	}
}

int	alpha(const t_stack *stack_a, int index)
{
	if (index == stack_a->top)
		return (0);
	return (index);
}

void bubble_sort_descending(t_stack *stack_a, t_stack *stack_b)
{
	printf("Running bubble_sort_descending()\n");
    int top_dup;
    int i;
    int k;
    int m;
    int temp;

    top_dup = stack_a->top - 1;
    i = 0;
    k = 0;
    m = 1;
    while (top_dup > -1)
    {
        while (i < top_dup)
        {
            if (stack_b->p_array[k] > stack_b->p_array[m])
            {
                temp = stack_b->p_array[m];
                stack_b->p_array[m] = stack_b->p_array[k];
                stack_b->p_array[k] = temp;
            }
            k = m;
            m = alpha(stack_a, m + 1);
            i++;
        }
        i = 0;
        k = 0;
        m = 1;
        top_dup--;
    }
}

void convert_stack_a_to_positive_ints(t_stack *stack_a, t_stack *stack_b)
{
	printf("Running convert_stack_a_to_positive_ints()\n");
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (i < stack_a->top)
	{
		while (j < stack_a->top)
		{
			if (stack_a->p_array[i] == stack_b->p_array[j])
            {
				stack_a->p_array[i] = j;
                break ;
            }
			j++;
		}
		j = 0;
		i++;
	}
}

int get_place_most_significant_set_bit(int x)
{
	int bits;

	bits = 0;
	while (x >> bits != 0)
		bits++;
	return (bits);
}

void radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	printf("Running radix_sort()\n");
	copy_stack_a_b(stack_a, stack_b);
	bubble_sort_descending(stack_a, stack_b);
	if (is_sorted(stack_b))
		printf("is_sorted == TRUE\n");
	else
		printf("is_sorted == FALSE\n");
	int	i;

	i = stack_a->top;
	printf("stack->name = %c\n", stack_b->stack_name);
	while (i)
	{
		printf("[%d] = %d\n", i - 1, stack_b->p_array[i - 1]);
		i--;
	}
	printf("----\n");
	convert_stack_a_to_positive_ints(stack_a, stack_b);

	int place_most_significant_set_bit = get_place_most_significant_set_bit(stack_a->top);
	printf("place_most_significant_set_bit = %u\n", place_most_significant_set_bit);

	int current_bit = 0;
	int j = 0;
    int top_dup = stack_a->top;
	while (current_bit < place_most_significant_set_bit)
	{
		while (j < top_dup)
		{
			if ( ( ( stack_a->p_array[stack_a->top - 1] >> current_bit ) & 1 ) == 1)
            {
				rotate_a_or_b(stack_a);
            }
			else
            {
				push(stack_a, stack_b);
            }
			j++;
		}
        while (stack_b->top)
        {
            push(stack_b, stack_a);
        }
        j = 0;
		current_bit++;
	}
}