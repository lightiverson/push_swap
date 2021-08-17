#include <stdio.h>
#include <unistd.h>
#include "./src/push_swap.h"
#include "./libft/libft.h"
#include "./src/setup_stacks/setup_stacks.h"

// int main(int argc, char *argv[])
// {
//     int i;

//     i = 0;

//     while (i < argc)
//     {
//         printf("argc = %s\n", argv[i]);
//         i++;
//     }
// }

// int main(int argc, char *argv[])
// {
//     char buf[9999];
//     int n;
//     char **split_result;

//     while ((n = read(0, buf, 9999)) > 0)
//     {
//         write(1, buf, n);
//     }
//     printf("\n\nbuf = %s\n", buf);
//     printf("n = %d\n", n);

//     split_result = ft_split(buf, '\n');
//     while (*split_result)
//     {
//         printf("split_result = %s\n", *split_result);
//         split_result++;
//     }

//     // creeer stacks dmv argc en argv
//     // importeer operations functies
//     // functie schrijven bijv: "rra" = reverse_rotate_a()
//     // 

//     return 0;
// }

// ./push_swap 0 2 1 | ./checker 0 2 1
// gcc checker.c -o checker ./libft/libft.a ./src/setup_stacks/setup_stacks.c ./src/utilities.c

int main(int argc, char *argv[])
{
    t_stack stacks['c'];

    initialize_stack(&(stacks['a']), argc - 1, 'a');
    populate_stack(argv, &(stacks['a']));
    initialize_stack(&(stacks['b']), argc - 1, 'b');
    print_stack(&(stacks['a']));
    print_stack(&(stacks['b']));
}