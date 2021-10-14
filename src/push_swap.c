#include "push_swap.h"

void alpha(t_stack *stack_a, t_stack *stack_b)
{
	printf("Running alpha()\n");
	int top_dup;
	int k;
	int temp;

	top_dup = stack_a->top - 1;
	k = 0;
	while (top_dup)
	{
		while (k < top_dup)
		{
			if (stack_a->p_array[k] < stack_a->p_array[k + 1])
			{
				temp = stack_a->p_array[k + 1];
				stack_a->p_array[k + 1] = stack_a->p_array[k];
				stack_a->p_array[k] = temp;
			}
			k++;
		}
		top_dup--;
		k = 0;
	}
}

// 1. malloc een nieuwe array van size stack
// 2. vul em met dezelfde getallen als stack
// 3. sorteer ze met bubble sort
// 4. match dan die kk index
void beta(t_stack *stack_a)
{
	printf("Running beta()\n");
	int *sorted_array;

	// Creeer malloced array
	sorted_array = malloc(sizeof(*sorted_array) * stack_a->len);
	if (sorted_array == NULL)
		exit(EXIT_FAILURE);

	// Copier stack a naar sorted array 
	int i = 0;
	while (i < stack_a->len)
	{
		sorted_array[i] = stack_a->p_array[i];
		i++;
	}

	// Print array om te controleren
	// int j = 0;
	// while (j < stack_a->len)
	// {
	// 	printf("[%d] = %d\n", j, sorted_array[j]);
	// 	j++;
	// }

	// Sorteer array
	int top_dup;
	int k;
	int temp;

	top_dup = stack_a->top - 1;
	k = 0;
	while (top_dup)
	{
		while (k < top_dup)
		{
			if (sorted_array[k] < sorted_array[k + 1])
			{
				temp = sorted_array[k + 1];
				sorted_array[k + 1] = sorted_array[k];
				sorted_array[k] = temp;
			}
			k++;
		}
		top_dup--;
		k = 0;
	}

	// Print array om te controleren
	int j = stack_a->len - 1;
	while (j >= 0)
	{
		printf("[%d] = %d\n", j, sorted_array[j]);
		j--;
	}

	// Vervang getallen in stack a door index getallen
	int *nieuwe_array;

	// Creeer malloced array
	nieuwe_array = malloc(sizeof(*nieuwe_array) * stack_a->len);
	if (nieuwe_array == NULL)
		exit(EXIT_FAILURE);

	int m = 0;
	int n = 0;
	while (m < stack_a->top)
	{
		while (n < stack_a->top)
		{
			if (stack_a->p_array[m] == sorted_array[n])
				nieuwe_array[m] = n;
			n++;
		}
		n = 0;
		m++;
	}
	
	printf("\n");

	// Print array om te controleren
	j = stack_a->len - 1;
	while (j >= 0)
	{
		printf("[%d] = %d\n", j, nieuwe_array[j]);
		j--;
	}

	printf("end of beta\n\n");
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
	beta(&(stacks[A]));
	
	// if (argc == 3 || argc == 4)
	// 	sort_three(&(stacks[A]));
	// else if (argc == 5 || argc == 6)
	// 	sort_five(&(stacks[A]), &(stacks[B]));

	print_stack(&(stacks[A]));
	print_stack(&(stacks[B]));

	free_stacks(&(stacks[A]), &(stacks[B]));

	return (0);
}
