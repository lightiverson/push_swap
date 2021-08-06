#include "../push_swap.h"

bool is_digit_or_minus_sign(int c)
{
	if (ft_isdigit(c) || c == '-')
		return (true);
	else
		return (false);
}

bool contains_non_int(int argc, char* argv[])
{
	int i;
	char *arg;

	i = 1;
	while (i < argc)
	{
		arg = argv[i];
		while (*arg)
		{
			if (!is_digit_or_minus_sign(*arg))
				return (true);
			arg++;
		}
		i++;
	}
	return (false);
}

bool is_error(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("ERROR: You need at least one argument.\n");
		return (true);
    }
	if (contains_non_int(argc, argv))
	{
		printf("ERROR: Contains non int\n");
		return true;
	}
	return (false);
}