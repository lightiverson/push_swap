NAME = push_swap
OBJ_FILES = push_swap.o \
			main.o
HEADER_FILES = push_swap.h
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT)
	$(CC) -o $(NAME) $(OBJ_FILES) $(LIBFT)

%.o: %.c $(HEADER_FILES)
	$(CC) -c -o $@ $<

$(LIBFT):
	make -C libft

clean:
	rm -f $(OBJ_FILES)
	make fclean -C libft

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re