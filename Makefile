CC = gcc 
CFLAGS = -Wall -Wextra -Iinclude

SRCS = main.c src/dlistas.c src/arreglos.c src/stack_arr.c
OBJS = $(SRCS:.c=.o)

programa: $(OBJS)
	$(CC) $(CFLAGS) -o programa $(OBJS)

%.o: %.CC
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f programa *.o