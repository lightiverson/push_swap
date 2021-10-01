#include <stdio.h>
#include <unistd.h>
#include "../src/push_swap.h"
#include "../libft/libft.h"
#include "../src/setup_stacks/setup_stacks.h"
#include "../src/error_checks/error_checks.h"
#include <string.h>

#define A   0
#define B   1

void check_for_int_and_overflow(int argc, char *argv[])
{
    int i;
    
    i = 1;
    while (i < argc)
    {
        // checks if element is integer
        // checks if element is bigger than integer
        ft_strtoi(argv[i]); 
        i++;
    }
}

void check_for_duplicates(int argc, char *argv[])
{
    int i;
    int j;

    i = 1;
    j = 1;
    while (i < argc)
    {
        while (j < argc)
        {
            if (i == j)
            {
                j++;
                continue;
            }
            if (!strcmp(argv[i], argv[j]))
                display_err_exit();
            j++;
        }
        j = 1;
        i++;
    }
}

int main(int argc, char *argv[])
{
    char buf[9999];
    int n;
    char **split_result;

    while ((n = read(0, buf, sizeof(buf))) > 0)
    {
        write(1, buf, n);
        line = strjoin(line, buf);
    }
    printf("buf = |%s|\n", buf);
    printf("n = %d\n", n);

    split_result = ft_split(buf, '\n');
    while (*split_result)
    {
        printf("split_result = %s\n", *split_result);
        split_result++;
    }

    // creeer stacks dmv argc en argv
    // importeer operations functies
    // functie schrijven bijv: "rra" = reverse_rotate_a()
    //

    // 1. while(get_next_line(stdin, char **line))
    // 3. zet **line in linked list
    // 2. free **line

    return 0;
}

// ./push_swap 0 2 1 | ./checker 0 2 1
// gcc checker.c -o checker ./libft/libft.a ./src/setup_stacks/setup_stacks.c ./src/utilities.c

// int main(int argc, char *argv[])
// {
//     t_stack stacks[2];

//     // if no argument is given checker stops and displays nothing
//     if (argc <= 1)
//         exit(EXIT_FAILURE);
//     check_for_int_and_overflow(argc, argv);
//     check_for_duplicates(argc, argv);


//     initialize_stack(&(stacks[A]), argc - 1, 'a');
//     populate_stack(argv, &(stacks[A]));
//     initialize_stack(&(stacks[B]), argc - 1, 'b');

//     print_stack(&(stacks[A]));
//     print_stack(&(stacks[B]));

//     // 1. Lees per byte? van de standard input.
//     // 2. Sla alles op in 1 string.
//     // 3. Gebruik ft_split om een array van strings te maken.
//     // 4. Loop over array en voor actions uit.

//     return (0);
// }