VPATH = ../src:../src/operations:../src/algorithms:../src/error_checks:../src/setup_stacks
NAME = checker
OBJ_FILES = checker.o \
			setup_stacks.o \
			utilities.o \
			error_checks.o
HEADER_FILES =	../src/setup_stacks/setup_stacks.h \
				../src/push_swap.h
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