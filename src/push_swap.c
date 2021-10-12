#include "push_swap.h"
#include "./algorithms/algorithms.h"
#include "./error_checks/error_checks.h"
#include "./setup_stacks/setup_stacks.h"
#include "./operations/operations.h"

int	main(int argc, char *argv[])
{
	t_stack	stacks[2];

	// if no argument is given stop and display nothing
	if (argc <= 1)
		exit(EXIT_FAILURE);
	check_for_int_and_overflow(argc, argv);
	check_for_duplicates(argc, argv);

	initialize_stack(&(stacks[A]), argc - 1, 'a');
	populate_stack(argc, argv, &(stacks[A]));
	initialize_stack(&(stacks[B]), argc - 1, 'b');

	print_stack(&(stacks[A]));
	print_stack(&(stacks[B]));

	if (is_sorted(&(stacks[A])))
	{
		printf("is_sorted() is True\n");
		free_stacks(&(stacks[A]), &(stacks[B]));
		return (0);
	}

	if (is_ordered(&(stacks[A])))
	{
		printf("is_ordered() is True\n");
		rotate_to_top(&(stacks[A]), get_minimum(&(stacks[A])));
		free_stacks(&(stacks[A]), &(stacks[B]));
		return (0);
	}

	if (argc == 3 || argc == 4)
		sort_three(&(stacks[A]));
	else if (argc == 5 || argc == 6)
		sort_five(&(stacks[A]), &(stacks[B]));

	print_stack(&(stacks[A]));
	print_stack(&(stacks[B]));

	free_stacks(&(stacks[A]), &(stacks[B]));

	return (0);
}
