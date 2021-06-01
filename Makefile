sources =	push_swap.c \
			main.c
objects =	push_swap.o \
			main.o
headers =	push_swap.h
prog =		push_swap
libft =		libft/libft.a

$(prog) : $(objects) $(libft)
			gcc -o $(prog) $(objects) $(libft)

$(libft) :
			make -C libft

$(objects) : $(sources)
			gcc $(sources) -c

clean :
	rm $(prog) $(objects)
	make fclean -C libft
