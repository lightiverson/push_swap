#include "push_swap.h"
#include "./algorithms/algorithms.h"

static void populate_stack(char *argv[], t_stack *stack)
{
    int i;
    int x;
    int j;

    i = 1;
    j = stack->len - 1;
    while (argv[i] != NULL) // Is het niet beter deze te vervangen door argc, aangezien array size daarop gebaseerd is?
    {
        x = ft_atoi(argv[i]);
        stack->p_array[j] = x;
        stack->top++;
        j--;
        i++;
    }
}

static void initialize_stack(t_stack *stack, int len, char stack_name)
{
    stack->p_array = ft_calloc(len, sizeof(*stack->p_array));
    if (stack->p_array == NULL)
    {
        printf("malloc failed\n");
        exit(EXIT_FAILURE);
    }
    stack->top = 0;
    stack->len = len;
    stack->stack_name = stack_name;
}

int main(int argc, char *argv[])
{
    t_stack stacks['c'];
	int minimum;

    initialize_stack(&(stacks['a']), argc - 1, 'a');
    populate_stack(argv, &(stacks['a']));
    initialize_stack(&(stacks['b']), argc - 1, 'b');
    #ifdef DEBUG
        print_stack(&(stacks['a']));
        print_stack(&(stacks['b']));
    #endif

	// General check: if this is the case no algo is really needed.
	if (is_sorted_a(&(stacks['a'])))
	{
		#ifdef DEBUG
			printf("is_sorted_a() == true\n");
			print_stack(&(stacks['a']));
			print_stack(&(stacks['b']));
		#endif
		return (0);
	}

	// General check: if this is the case no algo is really needed.
	if (is_ordered_a(&(stacks['a'])))
	{
		rotate_to_top(&(stacks['a']), minimum);
		#ifdef DEBUG
			printf("is_ordered_a() == true\n");
			print_stack(&(stacks['a']));
			print_stack(&(stacks['b']));
		#endif
		return (0);
	}

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

    sort_five(&(stacks['a']),&(stacks['b']));

	// sort_three(&(stacks['a']),&(stacks['b']));

    return (0);
}