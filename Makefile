CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

SRCS = main.c src/arreglos.c src/listas.c src/dlistas.c
OBJS = $(SRCS:.c=.o)

programa: $(OBJS)
	$(CC) $(CFLAGS) -o programa $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f programa *.o src/*.o
