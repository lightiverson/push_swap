#include "./mini_strtoi.h"

static void	handle_negative(int *p_number, int *p_digit)
{
	if ((*p_number > INT_MAX / 10) || ((*p_number == INT_MAX / 10)
			&& (*p_digit > INT_MAX % 10)))
		display_err_exit();
	*p_number = (*p_number * 10) + *p_digit;
}

static void	handle_positive(int *p_number, int *p_digit)
{
	if ((*p_number < INT_MIN / 10) || ((*p_number == INT_MIN / 10)
			&& (*p_digit > (INT_MIN % 10) * -1)))
		display_err_exit();
	*p_number = (*p_number * 10) - *p_digit;
}

int	mini_strtoi(const char *str)
{
	bool	is_negative;
	int		number;
	int		digit;

	if (*str == '-')
	{
		is_negative = true;
		str++;
	}
	number = 0;
	digit = 0;
	if (*str == '\0')
		display_err_exit();
	while (*str)
	{
		if (!ft_isdigit(*str))
			display_err_exit();
		digit = *str - '0';
		if (!is_negative)
			handle_negative(&number, &digit);
		else
			handle_positive(&number, &digit);
		str++;
	}
	return (number);
}
