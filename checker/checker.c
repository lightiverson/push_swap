#include "./checker.h"

static	void	free_display_err_exit(t_stack *stack_a, t_stack *stack_b)
{
	free_stacks(stack_a, stack_b);
	display_err_exit();
}

static	void	execute_operations(t_stack *stack_a, t_stack *stack_b, char *operation)
{
	if (!ft_strcmp(operation, "sa"))
		swap_a_or_b(stack_a);
	else if (!ft_strcmp(operation, "sb"))
		swap_a_or_b(stack_b);
	else if (!ft_strcmp(operation, "ss"))
		swap_ab(stack_a, stack_b);
	else if (!ft_strcmp(operation, "pa"))
		push(stack_b, stack_a);
	else if (!ft_strcmp(operation, "pb"))
		push(stack_a, stack_b);
	else if (!ft_strcmp(operation, "ra"))
		rotate_a_or_b(stack_a);
	else if (!ft_strcmp(operation, "rb"))
		rotate_a_or_b(stack_b);
	else if (!ft_strcmp(operation, "rr"))
		rotate_ab(stack_a, stack_b);
	else if (!ft_strcmp(operation, "rra"))
		reverse_rotate_a_or_b(stack_a);
	else if (!ft_strcmp(operation, "rrb"))
		reverse_rotate_a_or_b(stack_b);
	else if (!ft_strcmp(operation, "rrr"))
		reverse_rotate_ab(stack_a, stack_b);
	else
		free_display_err_exit(stack_a, stack_b);
}

static	void	write_ok_or_ko(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a) && stack_b->top == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char *argv[])
{
	t_stack	stacks[2];
	char	*line;
	int		is_malloc_failed;

	line = NULL;
	is_malloc_failed = 0;
	if (argc <= 1)
		exit(EXIT_FAILURE);
	check_for_int_and_overflow(argc, argv);
	is_malloc_failed = initialize_stack(&(stacks[A]), argc - 1, 'a');
	if (is_malloc_failed)
		exit(EXIT_FAILURE);
	populate_stack(argc, argv, &(stacks[A]));
	is_malloc_failed = initialize_stack(&(stacks[B]), argc - 1, 'b');
	if (is_malloc_failed)
	{
		free(&(stacks[A]).p_array);
		exit(EXIT_FAILURE);
	}
	exit_if_duplicate(&(stacks[A]), &(stacks[B]));
	while (get_next_line(0, &line))
		execute_operations(&(stacks[A]), &(stacks[B]), line);
	write_ok_or_ko(&(stacks[A]), &(stacks[B]));
	return (0);
}
