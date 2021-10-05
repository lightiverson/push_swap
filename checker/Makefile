VPATH = ../src:../src/operations:../src/algorithms:../src/error_checks:../src/setup_stacks:./get_next_line
NAME = checker
OBJ_FILES = checker.o \
			setup_stacks.o \
			utilities.o \
			error_checks.o \
			get_next_line.o \
			get_next_line_utils.o \
			reverse_rotate.o \
			is.o \
			gets.o \
			swap.o
HEADER_FILES =	checker.h
CFLAGS = -g
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