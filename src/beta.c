#include "push_swap.h"

void create_distance_array(int *p_array, int stack_len, int origin)
{
	int i;
	int distance_array[stack_len];

	i = 0;
	while (i < stack_len)
	{
		distance_array[i] = p_array[i] - origin;
		printf("distance_array[%d] = %d\n", i, distance_array[i]);
		i++;
	}

	int j;
	int k;
	int x;
	j = 0;
	k = 1;
	while (k < stack_len)
	{
		x =  distance_array[j] * distance_array[k];
		printf("x = %d\n", x);
		if (x < 0)
		{
			printf("index waar het getal moet komen = %d", j);
			return ;
		}
		j++;
		k++;
	}
}

int main(void)
{
	int array[] = {4, 3, 1};

	create_distance_array(array, 3, 2);
}