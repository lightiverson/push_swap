VPATH = ./operations:\
		../src:\
		../src/algorithms:\
		../src/error_checks:\
		../src/setup_stacks:\
		./get_next_line:\
		../src/mini_strtoi:\
		../src/is:\
		../src/gets
NAME = checker
OBJ_FILES = checker.o \
			setup_stacks.o \
			mini_strtoi.o \
			error_checks.o \
			get_next_line.o \
			get_next_line_utils.o \
			reverse_rotate.o \
			is.o \
			gets.o \
			swap.o \
			push.o \
			rotate.o
HEADER_FILES =	checker.h operations.h get_next_line.h
CFLAGS = -Wall -Wextra -Werror
LIBFT = ../libft/libft.a

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT)
	$(CC) -o $(NAME) $(OBJ_FILES) $(LIBFT)

%.o: %.c $(HEADER_FILES)
	$(CC) -c $(CFLAGS) -o $@ $<

$(LIBFT):
	make -C ../libft

clean:
	rm -f $(OBJ_FILES)
	make fclean -C ../libft

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re