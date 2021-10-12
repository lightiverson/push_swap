VPATH = ./src:./src/error_checks:./src/mini_strtoi:./src/setup_stacks:./src/gets:./src/is:./src/utilities_algorithms:./src/algorithms:./src/operations
NAME = push_swap
OBJ_FILES = push_swap.o \
			setup_stacks.o \
			mini_strtoi.o \
			error_checks.o \
			reverse_rotate.o \
			is.o \
			gets.o \
			swap.o \
			push.o \
			rotate.o \
			utilities_algorithms.o \
			sort_three.o \
			sort_five.o
HEADER_FILES = push_swap.h struct.h
CFLAGS = -g
LIBFT = libft/libft.a

all: $(NAME)

debug: CFLAGS += -D DEBUG
debug: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT)
	$(CC) -o $(NAME) $(OBJ_FILES) $(LIBFT)

%.o: %.c $(HEADER_FILES)
	$(CC) -c $(CFLAGS) -o $@ $<

$(LIBFT):
	make -C libft

clean:
	rm -f $(OBJ_FILES)
	make fclean -C libft

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re