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

    if (argc == 3 || argc == 4)
    	sort_three(&(stacks['a']));
    else if (argc == 5 || argc == 6)
        sort_five(&(stacks['a']), &(stacks['b']));

    print_stack(&(stacks['a']));
    print_stack(&(stacks['b']));

    free_stacks(&(stacks['a']), &(stacks['b']));

    return (0);
}