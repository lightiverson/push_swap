#include "./error_checks.h"

void	display_err_exit(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	check_for_int_and_overflow(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		mini_strtoi(argv[i]);
		i++;
	}
}

void	check_for_duplicates(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stack_a->top)
	{
		while (j < stack_a->top)
		{
			if (i == j)
			{
				j++;
				continue ;
			}
			if (stack_a->p_array[i] == stack_a->p_array[j])
			{
				free_stacks(stack_a, stack_b);
				display_err_exit();
			}
			j++;
		}
		j = 0;
		i++;
	}
}
