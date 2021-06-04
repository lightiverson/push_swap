#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

void push_swap(void);
#include <stdio.h>
#include "./libft/libft.h"

// Define struct to represent stack datatype
typedef struct s_stack
{
    int *p_array;
    int top;
    int len;
} t_stack;

#endif /* PUSH_SWAP_H */