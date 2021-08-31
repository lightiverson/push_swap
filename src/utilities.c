#include "push_swap.h"

void print_stack(const t_stack *stack)
{
    int i;

    i = stack->top;
    printf("stack->name = %c\n", stack->stack_name);
    while (i)
    {
        printf("[%d] = %d\n", i - 1, stack->p_array[i - 1]);
        i--;
    }
    printf("----\n");
}

void free_stacks(t_stack *stack_a, t_stack *stack_b)
{
    free(stack_a->p_array);
    free(stack_b->p_array);
}

void beta(t_stack *stack, int origin)
{
	int i;
	int distance_array[stack->len];

	i = 0;
	while (i < stack->len)
	{
		distance_array[i] = stack->p_array[i] - origin;
		printf("distance_array[%d] = %d\n", i, distance_array[i]);
		i++;
	}

	int min;
	min = get_minimum(stack);
	if (origin < min)
	{
		printf("push b op index van min\n");
		return;
	}

	int max;
	max = get_maximum(stack);
	if (origin > max)
	{
		printf("push b op index van max\n");
		return;
	}

	int j;
	int k;
	int x;
	j = 0;
	k = 1;
	while (k < stack->len)
	{
		x =  distance_array[j] * distance_array[k];
		printf("x = %d\n", x);
		if (x < 0)
		{
			printf("index waar het getal moet komen = %d\n", j);
			return ;
		}
		j++;
		k++;
	}
}

// void print_stack(const t_stack *stack)
// {
//     int i;

//     i = 0;
//     printf("stack->name = %c\n", stack->stack_name);
//     while (i < stack->top)
//     {
//         printf("%d", stack->p_array[i]);
//         if (i != stack->top - 1)
//             printf(", ");
//         i++;
//     }
//     printf("\n----\n");
// }