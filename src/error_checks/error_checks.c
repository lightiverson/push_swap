#include "../push_swap.h"

void display_err_exit(void)
{
    write(STDERR_FILENO, "Error\n", 6);
    exit(EXIT_FAILURE);
}

void check_for_int_and_overflow(int argc, char *argv[])
{
    int i;
    
    i = 1;
    while (i < argc)
    {
        mini_strtoi(argv[i]); 
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