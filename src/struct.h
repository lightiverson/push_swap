#ifndef STRUCT_H
# define STRUCT_H

// Define struct to represent stack datatype
typedef struct s_stack
{
	int		*p_array;
	int		top;
	int		len;
	char	stack_name;
}	t_stack;

#endif /* STRUCT_H */