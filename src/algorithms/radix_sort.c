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

void bubble_sort_descending(t_stack *stack_a, t_stack *stack_b)
{
	printf("Running bubble_sort_descending()\n");
	int top_dup;
	int i;
	int temp;

	top_dup = stack_a->top;
	i = 0;
	while (top_dup)
	{
		while (i < top_dup)
		{
			if (stack_b->p_array[i] < stack_b->p_array[i + 1])
			{
				temp = stack_b->p_array[i + 1];
				stack_b->p_array[i + 1] = stack_b->p_array[i];
				stack_b->p_array[i] = temp;
			}
			i++;
		}
		i = 0;
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
				stack_a->p_array[i] = j;
			j++;
		}
		j = 0;
		i++;
	}
}

unsigned int get_place_most_significant_set_bit(unsigned int x)
{
	unsigned int bits;

	bits = 0;
	while (x >> bits != 0)
		bits++;
	return (bits);
}

void radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	printf("Running radix_sort()\n");
	// copy_stack_a_b(stack_a, stack_b);
	// bubble_sort_descending(stack_a, stack_b);
	// if (is_sorted(stack_b))
	// 	printf("is_sorted == TRUE\n");
	// else
	// 	printf("is_sorted == FALSE\n");
	// convert_stack_a_to_positive_ints(stack_a, stack_b);

	unsigned int place_most_significant_set_bit = get_place_most_significant_set_bit(36);
	printf("place_most_significant_set_bit = %d\n", place_most_significant_set_bit);

	int current_bit = 0;
	int j = 0;
	while (current_bit < place_most_significant_set_bit)
	{
		while (j < stack_a->top)
		{
			if ( ( ( stack_a->p_array[j] >> current_bit ) & 1 ) == 1)
				rotate_a_or_b(stack_a);
			else
				push(stack_a, stack_b);
			j++;
		}
		current_bit++;
	}
}