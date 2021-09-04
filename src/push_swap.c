#include "push_swap.h"
#include "./algorithms/algorithms.h"
#include "./error_checks/error_checks.h"
#include "./setup_stacks/setup_stacks.h"
#include "./operations/operations.h"

int main(int argc, char *argv[])
{
    t_stack stacks['c'];

    initialize_stack(&(stacks['a']), argc - 1, 'a');
    populate_stack(argv, &(stacks['a']));
    initialize_stack(&(stacks['b']), argc - 1, 'b');
    print_stack(&(stacks['a']));
    print_stack(&(stacks['b']));

    if (argc < 5)
    	// sort_three(&(stacks['a']), &(stacks['b']));
    	// alpha(&(stacks['a']));
    	beta(&(stacks['a']));
    else if (argc < 7)
        sort_five(&(stacks['a']), &(stacks['b']));

    // int *p_distance_array = create_distance_array(&(stacks['a']), 2);
    // get_insert_index(&(stacks['a']), 7);
    // get_minimum_positive(&(stacks['a']));
    // get_insert_value(&(stacks['a']), 3);

    print_stack(&(stacks['a']));
    print_stack(&(stacks['b']));
    free_stacks(&(stacks['a']), &(stacks['b']));

	// General check: if this is the case no algo is really needed.
	// if (is_sorted_a(&(stacks['a'])))
	// {
	// 	#ifdef DEBUG
	// 		printf("is_sorted_a() == true\n");
	// 		print_stack(&(stacks['a']));
	// 		print_stack(&(stacks['b']));
	// 	#endif
	// 	return (0);
	// }

	// General check: if this is the case no algo is really needed.
	// if (is_ordered_a(&(stacks['a'])))
	// {
	// 	rotate_to_top(&(stacks['a']), get_minimum(&(stacks['a'])));
	// 	#ifdef DEBUG
	// 		printf("is_ordered_a() == true\n");
	// 		print_stack(&(stacks['a']));
	// 		print_stack(&(stacks['b']));
	// 	#endif
	// 	return (0);
	// }

	// bubble_sort(&stacks['a']);

    // sort_three(&(stacks['a']));

    // split_stack_ab(&(stacks['a']),&(stacks['b']));
    // print_stack(&(stacks['a']));
    // print_stack(&(stacks['b']));

    // sort_three(&(stacks['a']));
    // sort_three(&(stacks['b']));
    // print_stack(&(stacks['a']));
    // print_stack(&(stacks['b']));

    // printf("%d", is_ordered(&(stacks['a'])));

    // sort_five(&(stacks['a']),&(stacks['b']));

    // is_sorted_a(&(stacks['a']));

    return (0);
}