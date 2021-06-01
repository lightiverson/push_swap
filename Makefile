sources =	push_swap.c \
			main.c
objects =	push_swap.o \
			main.o
headers =	push_swap.h
prog =		push_swap

$(prog) : $(objects)
			gcc -o $(prog) $(objects)

$(objects) : $(sources)
			gcc $(sources) $(headers) -c

clean :
	rm $(prog) $(objects)