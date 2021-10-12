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

void	check_for_duplicates(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i < argc)
	{
		while (j < argc)
		{
			if (i == j)
			{
				j++;
				continue ;
			}
			if (!ft_strcmp(argv[i], argv[j]))
				display_err_exit();
			j++;
		}
		j = 1;
		i++;
	}
}
