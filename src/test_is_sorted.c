#include "push_swap.h"
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include "./setup_stacks/setup_stacks.h"

int main(int argc, char *argv[])
{
    bool x;
    t_stack stacks['c'];

    initialize_stack(&(stacks[A]), argc - 1, 'a');
    populate_stack(argc, argv, &(stacks[A]));
    initialize_stack(&(stacks[B]), argc - 1, 'b');

    x = is_sorted(&(stacks[A]));
    printf("is_sorted = %d", x);
    return (0);
}