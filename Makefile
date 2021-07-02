NAME = push_swap
OBJ_FILES = push_swap.o \
			operations.o \
			utilities.o
HEADER_FILES = push_swap.h
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