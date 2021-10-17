#include "push_swap.h"

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

	radix_sort(&(stacks[A]), &(stacks[B]));
	// copy_stack_a_b(&(stacks[A]), &(stacks[B]));
	// bubble_sort_descending(&(stacks[A]), &(stacks[B]));
	// if (is_sorted(&(stacks[B])))
	// 	printf("is_sorted == TRUE\n");
	// else
	// 	printf("is_sorted == FALSE\n");
	// convert_stack_a_to_positive_ints(&(stacks[A]), &(stacks[B]));
	
	// if (argc == 3 || argc == 4)
	// 	sort_three(&(stacks[A]));
	// else if (argc == 5 || argc == 6)
	// 	sort_five(&(stacks[A]), &(stacks[B]));

	print_stack(&(stacks[A]));
	print_stack(&(stacks[B]));

	free_stacks(&(stacks[A]), &(stacks[B]));

	return (0);
}
