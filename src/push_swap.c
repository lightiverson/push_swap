#include "push_swap.h"

void charlie (t_stack *stack_a, t_stack *stack_b)
{
    printf("Running charlie()\n");
    // Kopier stack_a naar stack_b
	int i = 0;
	while (i < stack_a->top)
	{
		stack_b->p_array[i] = stack_a->p_array[i];
		i++;
	}

	// Vul stack_b met alles van stack_a maar gesorteerd
	int top_dup;
	int k;
	int temp;

	top_dup = stack_a->top - 1;
	k = 0;
	while (top_dup)
	{
		while (k < top_dup)
		{
			if (stack_b->p_array[k] < stack_b->p_array[k + 1])
			{
				temp = stack_b->p_array[k + 1];
				stack_b->p_array[k + 1] = stack_b->p_array[k];
				stack_b->p_array[k] = temp;
			}
			k++;
		}
		top_dup--;
		k = 0;
	}

    // Print array
	i = stack_a->top;
	while (i)
	{
		printf("[%d] = %d\n", i - 1, stack_b->p_array[i - 1]);
		i--;
	}

    // Vul stack a met opeenvolgende positieve ints.
	int m = 0;
	int n = 0;
	while (m < stack_a->top)
	{
		while (n < stack_a->top)
		{
			if (stack_a->p_array[m] == stack_b->p_array[n])
				stack_a->p_array[m] = n;
			n++;
		}
		n = 0;
		m++;
	}
    printf("end of charlie\n\n");
}

int	main(int argc, char *argv[])
{
	t_stack	stacks[2];

	// if no argument is given stop and display nothing
	if (argc <= 1)
		exit(EXIT_FAILURE);
	check_for_int_and_overflow(argc, argv);
	initialize_stack(&(stacks[A]), argc - 1, 'a');
	populate_stack(argc, argv, &(stacks[A]));
	initialize_stack(&(stacks[B]), argc - 1, 'b');
	check_for_duplicates_twee(&(stacks[A]), &(stacks[B]));

	print_stack(&(stacks[A]));
	print_stack(&(stacks[B]));

	// if (is_sorted(&(stacks[A])))
	// {
	// 	printf("is_sorted() is True\n");
	// 	free_stacks(&(stacks[A]), &(stacks[B]));
	// 	return (0);
	// }

	// if (is_ordered(&(stacks[A])))
	// {
	// 	printf("is_ordered() is True\n");
	// 	rotate_to_top(&(stacks[A]), get_minimum(&(stacks[A])));
	// 	free_stacks(&(stacks[A]), &(stacks[B]));
	// 	return (0);
	// }

	// alpha(&(stacks[A]), &(stacks[B]));
	// if (is_sorted(&(stacks[A])))
	// 	printf("is_sorted == TRUE\n");
	// else
	// 	printf("is_sorted == FALSE\n");
	// beta(&(stacks[A]));
	charlie(&(stacks[A]), &(stacks[B]));
	
	// if (argc == 3 || argc == 4)
	// 	sort_three(&(stacks[A]));
	// else if (argc == 5 || argc == 6)
	// 	sort_five(&(stacks[A]), &(stacks[B]));

	print_stack(&(stacks[A]));
	print_stack(&(stacks[B]));

	free_stacks(&(stacks[A]), &(stacks[B]));

	return (0);
}
