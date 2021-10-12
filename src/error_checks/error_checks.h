#ifndef ERROR_CHECKS_H
# define ERROR_CHECKS_H

# include <stdlib.h>
# include <unistd.h>
# include "../mini_strtoi/mini_strtoi.h"

void	display_err_exit(void);
int		ft_strcmp(const char *s1, const char *s2);
void	check_for_int_and_overflow(int argc, char *argv[]);
void	check_for_duplicates(int argc, char *argv[]);

#endif /* ERROR_CHECKS_H */